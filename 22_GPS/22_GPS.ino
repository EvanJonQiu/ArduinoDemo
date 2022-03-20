#include <SoftwareSerial.h>

SoftwareSerial mySerial(8, 9);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Begin setup ATGM332D");
  while (!Serial) {
    ;
  }

  Serial.println("Board serial is OK");
  mySerial.begin(9600);
  mySerial.println("ATGM332D is OK");
}

void loop() {
  // put your main code here, to run repeatedly:
  if (mySerial.available()) {
    Serial.write(mySerial.read());
  }
}
