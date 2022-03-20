#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9); //rx, tx

void setup() {
  Serial.begin(115200);
  Serial.println("Begin setup ESP");
  while (!Serial) {
    ;
  }

  Serial.println("Board serial is OK");
  mySerial.begin(115200);
  mySerial.println("ESP is OK");
}

void loop() {
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
  if (Serial.available()) {
    mySerial.write(Serial.read());
  }
}
