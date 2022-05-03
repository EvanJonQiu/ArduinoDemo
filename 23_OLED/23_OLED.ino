 #include <Wire.h>
 #include <Adafruit_GFX.h>
 #include <Adafruit_SSD1306.h>
 #define OLED_RESET 4
 #define screen_x 128
 #define screen_y 32

 Adafruit_SSD1306 display(screen_x, screen_y, &Wire, OLED_RESET);
 
 void setup() {
  // put your setup code here, to run once:
  display.begin(SSD1306_SWITCHCAPVCC, 0x3c);
}

void loop() {
  // put your main code here, to run repeatedly:
  words();
  display.display();
}

void words() {
  display.setTextColor(WHITE);
  display.clearDisplay();
  display.setTextSize(2);
  display.setCursor(15, 15);
  display.println("good");
}
