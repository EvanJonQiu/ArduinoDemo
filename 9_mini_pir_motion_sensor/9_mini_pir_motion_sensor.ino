#define PIR_MOTION_SENSOR 2

void setup() {
  // put your setup code here, to run once:
  pinMode(PIR_MOTION_SENSOR, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(PIR_MOTION_SENSOR) == HIGH) {
    Serial.println("Hi, people is coming");
  } else {
    Serial.println("Watching");
  }
  delay(500);
}
