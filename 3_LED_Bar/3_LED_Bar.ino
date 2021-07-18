#include <Grove_LED_Bar.h>

Grove_LED_Bar bar(7, 6, 0);

void setup() {
  bar.begin();
}

void loop() {
  // all
  bar.setBits(0x3ff);
  delay(1000);

  // all
  bar.setBits(0x0);
  delay(1000);

  // 1
  bar.setBits(0b000000000000001);
  delay(1000);

  // 1, 3
  bar.setBits(0b000000000000101);
  delay(1000);

  // 1, 3, 5, 7, 9
  bar.setBits(0x155);
  delay(1000);

  // 2, 4, 6, 8, 10
  bar.setBits(0x2AA);
  delay(1000);

  // 1, 2, 3, 4, 5
  bar.setBits(0b000000000011111);
  delay(1000);

  // 6, 7, 8, 9, 10
  bar.setBits(0b000001111100000);
  delay(1000);
}
