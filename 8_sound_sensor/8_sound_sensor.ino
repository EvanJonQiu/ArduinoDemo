const int pinAdc = A0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  long sum = 0;
  for (int i = 0; i < 32; i++) {
    sum += analogRead(pinAdc);
  }

  sum >>= 5;

  Serial.println(sum);
  delay(100);
}
