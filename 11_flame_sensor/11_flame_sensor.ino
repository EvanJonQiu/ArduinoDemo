#define FLAME_SENSOR 3
#define LED 2

void setup() {
  // put your setup code here, to run once:
  pinsInit();
}

void loop() {
  // put your main code here, to run repeatedly:
  if (isFlameDetected()) {
    turnOnLED();
  } else {
    turnOffLED();
  }
}

void pinsInit() {
  pinMode(FLAME_SENSOR, INPUT);
  pinMode(LED, LOW);
  digitalWrite(LED, LOW);
}

void turnOnLED() {
  digitalWrite(LED, HIGH);
}

void turnOffLED() {
  digitalWrite(LED, LOW);
}

boolean isFlameDetected() {
  if (digitalRead(FLAME_SENSOR)) {
    return false;
  } else {
    return true;
  }
}
