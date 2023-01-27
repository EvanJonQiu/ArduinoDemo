#include <SoftwareSerial.h>

SoftwareSerial BT(10, 11);
char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Serial.println("bluetooth is ready!");
  BT.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()) {
    val = Serial.read();
    Serial.println(val);
    BT.print(val);
  }
 
  if (BT.available()) {
    val = BT.read();
    Serial.print(val);
  }

}
