#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_W_u16 128
#define OLED_H_u8 64
#define SCREEN_Addr_u8 0x3C 
#define OLED_RESET_i8 -1
#define textSize_u8 1

Adafruit_SSD1306 display(OLED_W_u16, OLED_H_u8, &Wire, OLED_RESET_i8);

void setup() 
{
  if(!display.begin(SSD1306_SWITCHCAPVCC, SCREEN_Addr_u8)) {
    Serial.println(F("oLED Module not Found!"));
    for(;;);                          
  }
  delay(3000);
  display.clearDisplay();
  display.setTextSize(textSize_u8);             
  display.setTextColor(SSD1306_WHITE);
  display.setCursor(0,0);             
  display.println(F("Welcome !"));
  display.display();
  delay(2000);
}

void loop() {
  // put your main code here, to run repeatedly:
  delay(10); // this speeds up the simulation
}
