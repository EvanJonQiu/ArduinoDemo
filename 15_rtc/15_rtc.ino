#include <Time.h>
#include <Wire.h>
#include <DS1307RTC.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  setSyncProvider(RTC.get);
  if (timeStatus() != timeSet) {
    Serial.println("unable to sync with the RTC");
  } else {
    Serial.println("RTC has set the system time");
  }
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalClockDisplay();
  delay(1000);
}

void digitalClockDisplay() {
  Serial.print(hour());
  printDigits(minute());
  printDigits(second());
  Serial.print(" ");
  Serial.print(day());
  Serial.print(" ");
  Serial.print(month());
  Serial.print(" ");
  Serial.print(year());
  Serial.println();
}

void printDigits(int digits){
  Serial.print(":");
  if(digits < 10)
    Serial.print('0'); 
   Serial.print(digits);
}

#define TIME_MSG_LEN 11
#define TIME_HEADER 'T'

time_t processSyncMessage() {
  // return the time if a valid sync message is received on the serial port. // time message consists of a header and ten ascii digits while(Serial.available() >= TIME_MSG_LEN ){
  char c = Serial.read() ; Serial.print(c);
  if( c == TIME_HEADER ) {
    time_t pctime = 0;
    for(int i=0; i < TIME_MSG_LEN -1; i++){
      c = Serial.read();
      if( c >= '0' && c <= '9'){
        pctime = (10 * pctime) + (c - '0') ; // convert digits to a number }
      }
      return pctime; }
    }
  return 0;
}
