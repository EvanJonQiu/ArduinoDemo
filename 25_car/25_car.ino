#include <SoftwareSerial.h>

SoftwareSerial BT(3, 4);

const int left_front_1 = 5;
const int left_front_2 = 7;
const int left_end_1 = 6;
const int left_end_2 = 8;
const int right_front_1 = 10;
const int right_front_2 = 12;
const int right_end_1 = 11;
const int right_end_2 = 13;

char val;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600); 
  Serial.println("bluetooth is ready!");
  BT.begin(9600);

  pinMode(left_front_1, OUTPUT);
  pinMode(left_front_2, OUTPUT);
  pinMode(left_end_1, OUTPUT);
  pinMode(left_end_2, OUTPUT);

  pinMode(right_front_1, OUTPUT);
  pinMode(right_front_2, OUTPUT);
  pinMode(right_end_1, OUTPUT);
  pinMode(right_end_2, OUTPUT);

  digitalWrite(left_front_1, LOW);
  digitalWrite(left_front_2, LOW);
  digitalWrite(left_end_1, LOW);
  digitalWrite(left_end_2, LOW);

  digitalWrite(right_front_1, LOW);
  digitalWrite(right_front_2, LOW);
  digitalWrite(right_end_1, LOW);
  digitalWrite(right_end_2, LOW);
}

void loop() {
  if (BT.available()) {
    char newVal = BT.read();
    Serial.print(val);
    if (newVal != val) {
      val = newVal;
      if (val == 'A') {
        digitalWrite(left_front_1, LOW);
        digitalWrite(left_front_2, LOW);
        digitalWrite(left_end_1, LOW);
        digitalWrite(left_end_2, LOW);

        digitalWrite(right_front_1, LOW);
        digitalWrite(right_front_2, LOW);
        digitalWrite(right_end_1, LOW);
        digitalWrite(right_end_2, LOW);
      } else if (val == 'G') {
        digitalWrite(left_front_1, HIGH);
        digitalWrite(left_front_2, LOW);
        digitalWrite(left_end_1, HIGH);
        digitalWrite(left_end_2, LOW);

        digitalWrite(right_front_1, HIGH);
        digitalWrite(right_front_2, LOW);
        digitalWrite(right_end_1, HIGH);
        digitalWrite(right_end_2, LOW);
      } else if (val == 'K') {
        digitalWrite(left_front_1, LOW);
        digitalWrite(left_front_2, HIGH);
        digitalWrite(left_end_1, LOW);
        digitalWrite(left_end_2, HIGH);

        digitalWrite(right_front_1, LOW);
        digitalWrite(right_front_2, HIGH);
        digitalWrite(right_end_1, LOW);
        digitalWrite(right_end_2, HIGH);
      } else if (val == 'H') { //left
        digitalWrite(left_front_1, HIGH);
        digitalWrite(left_front_2, LOW);
        digitalWrite(left_end_1, LOW);
        digitalWrite(left_end_2, HIGH);

        digitalWrite(right_front_1, HIGH);
        digitalWrite(right_front_2, LOW);
        digitalWrite(right_end_1, LOW);
        digitalWrite(right_end_2, HIGH);
      } else if (val == 'J') { // right
        digitalWrite(left_front_1, LOW);
        digitalWrite(left_front_2, HIGH);
        digitalWrite(left_end_1, HIGH);
        digitalWrite(left_end_2, LOW);

        digitalWrite(right_front_1, LOW);
        digitalWrite(right_front_2, HIGH);
        digitalWrite(right_end_1, HIGH);
        digitalWrite(right_end_2, LOW);
      }
    }
  }
}
