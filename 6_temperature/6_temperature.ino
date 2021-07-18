#include <math.h>

int a;
float temperature;
int B = 3975;
float resistance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  a = analogRead(0);
  resistance = (float)(1023 - a) * 10000 / a;
  temperature = 1 / (log(resistance / 10000) / B + 1 /298.15) - 273.15;
  delay(1000);
  Serial.print("Current temperature is ");
  Serial.println(temperature);
}
