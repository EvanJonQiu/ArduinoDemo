const int irReceiverPin = 2;

void setup() {
  pinMode(irReceiverPin, INPUT);
  Serial.begin(9600);
  attachInterrupt(digitalPinToInterrupt(irReceiverPin), analyze, CHANGE);
}

void loop() {
  Serial.println("hello");
  delay(1000);
}

void analyze() {
  if (digitalRead(irReceiverPin) == LOW) {
    Serial.println("down");
  } else {
    Serial.println("up");
  }
}