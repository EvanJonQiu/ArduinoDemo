int MoPin = 2;

void setup() {
  // put your setup code here, to run once:
  pinMode(MoPin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(MoPin, HIGH);
  delay(1000);

  digitalWrite(MoPin, LOW);
  delay(1000);
}
