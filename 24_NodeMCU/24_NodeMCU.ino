#include <ESP8266WiFi.h>
#include <PubSubClient.h>
#include <SoftwareSerial.h>
#include <TinyGPS++.h>

const char *ssid = "SSID";
const char *password = "PASSWORD";
const char *mqtt_server = "IP";
const int mqtt_server_port = <PORT>;

const char *client_id = "client_id";
const char *mqtt_user = "username";
const char *mqtt_password = "password";

const char *topic = "test/topic";

struct
{
  char GPS_Buffer[80];
  bool isGetData;   //是否获取到GPS数据
  bool isParseData; //是否解析完成
  char UTCTime[11];   //UTC时间
  char latitude[11];    //纬度
  char N_S[2];    //N/S
  char longitude[12];   //经度
  char E_W[2];    //E/W
  bool isUsefull;   //定位信息是否有效
} Save_Data;

const unsigned int gpsRxBufferLength = 100;
char gpsRxBuffer[gpsRxBufferLength];
unsigned int ii = 0;

TinyGPSPlus gps;
WiFiClient espClient;
PubSubClient client(espClient);
SoftwareSerial gpsSerial(13, 15);

void setup_wifi();
void reconnect();
void clrGpsRxBuffer();

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.print("Connection to ");
  Serial.println(ssid);

  setup_wifi();

  client.setServer(mqtt_server, mqtt_server_port);

  gpsSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (!client.connected()) {
    reconnect();
  }

  gpsRead();
  if (Save_Data.isGetData) {
    //Serial.println(Save_Data.GPS_Buffer);
    client.publish(topic, Save_Data.GPS_Buffer);
  }

  client.loop();

}

void setup_wifi() {
  delay(100);
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }

  Serial.println("WiFi connected");
  Serial.println(WiFi.localIP());
}

void reconnect() {
  if (WiFi.status() != WL_CONNECTED) {
    Serial.println("WiFi is not connected, retry setup");
    setup_wifi();
  }

  while (!client.connected()) {
    Serial.println("MQTT connecting...");
    if (client.connect(client_id, mqtt_user, mqtt_password)) {
      Serial.println("MQTT connect success.");
    } else {
      delay(5000);
    }
  }
}

void gpsRead() {
  while (gpsSerial.available()) {
    gpsRxBuffer[ii++] = gpsSerial.read();
    if (ii == gpsRxBufferLength)clrGpsRxBuffer();
  }

  char* GPS_BufferHead;
  char* GPS_BufferTail;
  if ((GPS_BufferHead = strstr(gpsRxBuffer, "$GPRMC,")) != NULL || (GPS_BufferHead = strstr(gpsRxBuffer, "$GNRMC,")) != NULL )
  {
    if (((GPS_BufferTail = strstr(GPS_BufferHead, "\r\n")) != NULL) && (GPS_BufferTail > GPS_BufferHead))
    {
      //memset(Save_Data.GPS_Buffer, 0, 80);
      memcpy(Save_Data.GPS_Buffer, GPS_BufferHead, GPS_BufferTail - GPS_BufferHead);
      
      Save_Data.isGetData = true;

      clrGpsRxBuffer();
    }
  }
}

void clrGpsRxBuffer() {
  memset(gpsRxBuffer, '\0', gpsRxBufferLength);      //清空
  ii = 0;
}
