#include <TM1637.h>

#define CLK 2
#define DIO 3

boolean point_flag = POINT_ON;

TM1637 tm1637(CLK, DIO);

void setup() {
  // put your setup code here, to run once:
  tm1637.init();
  tm1637.set(BRIGHT_TYPICAL);
}

void loop() {
  // put your main code here, to run repeatedly:
  int8_t NumTab[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
  int8_t ListDisp[4];
  unsigned char i = 0;
  unsigned char count = 0;

  delay(150);
  while (1) {
    i = count;
    count++;
    if (count == sizeof(NumTab)) count = 0;
    for (unsigned char BitSelect = 0; BitSelect < 4; BitSelect++) {
      ListDisp[BitSelect] = NumTab[i];
      i++;
      if (i == sizeof(NumTab)) i = 0;
    }
    tm1637.display(0, ListDisp[0]);
    tm1637.display(1, ListDisp[1]);
    tm1637.display(2, ListDisp[2]);
    tm1637.display(3, ListDisp[3]);
    tm1637.point(point_flag);
    point_flag = !point_flag;
    delay(1000);
  }
}
