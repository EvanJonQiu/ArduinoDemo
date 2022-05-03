#include <SoftwareSerial.h>

/**
 * AT command
 * 
 * AT+RESTORE
 * AT+CWMODE=1
 * AT+RST
 * AT+CWJAP="ssid","password"
 * AT+CIFSR
 * AT+CIPMUX=0
 * AT+CIPMODE=1
 * AT+CIPSTART="TCP","IP",<port number>
 * AT+CIPSEND=5
 * <input 5 charactor like: hello>
 */

SoftwareSerial WifiSerial(10, 11);  //rx, tx

void setup() {
  Serial.begin(115200);
  Serial.println("Begin setup ESP");
  while (!Serial) {
    ;
  }

  Serial.println("Board serial is OK");
  WifiSerial.begin(115200);
  WifiSerial.write("AT+CIPMUX=0\r\n");
  delay(100);
  WifiSerial.write("AT+CIPMODE=1\r\n");
  delay(100);
  WifiSerial.write("AT+CIPSTART=\"TCP\",\"<IP>\",<PORT>\r\n");
  delay(100);
}

void loop() {
  if (WifiSerial.available()) {
    Serial.write(WifiSerial.read());
  }
  if (Serial.available()) {
    WifiSerial.write(Serial.read());
  }
}
