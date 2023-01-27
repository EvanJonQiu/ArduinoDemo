#include <SoftwareSerial.h>

SoftwareSerial softSerial(10, 11);
String s = "";

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  softSerial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0) {
    Serial.println(Serial.read());
    softSerial.write(Serial.read());
  }

  if (softSerial.available() > 0) {
    s = softSerial.readString();
    Serial.println(s);
  }
}
