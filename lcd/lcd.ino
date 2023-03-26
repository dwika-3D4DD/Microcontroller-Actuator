#include <LiquidCrystal_I2C.h>
#include <Wire.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  // put your setup code here, to run once:
  lcd.begin(16, 2);
  lcd.backlight();
  lcd.clear();
  lcd.setCursor (0, 0);
  lcd.print("Hello World "); //cetak ke LCD
  lcd.setCursor (0, 1);
  lcd.print("Goodbye World");
}

void loop() {
  // put your main code here, to run repeatedly:

}
