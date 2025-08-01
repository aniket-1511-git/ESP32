
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

#define Seria_bouadRate_u16 9600

#define LCD_Addr_u8 0x27
#define LCD_Col_u8  16
#define LCD_Row_u8  2

LiquidCrystal_I2C lcd(LCD_Addr_u8,LCD_Col_u8,LCD_Row_u8);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(Seria_bouadRate_u16);
  Serial.println("ESP 32 LCD INTERFACE ");
  lcd.init();
  lcd.backlight();
}

void loop() {
   lcd.setCursor(0,0);
  lcd.print("Welcome to ESP32");
  lcd.setCursor(0,1);
  lcd.print("    Tutorial");

}
