#include <LiquidCrystal.h>

LiquidCrystal lcd(11, 10, 5, 4, 3, 2);

void setup(){
  lcd.begin(16,2);
  lcd.print("Hello!!!");
  lcd.setCursor(0,1);
  lcd.print("Time: ");
}

void loop(){
  lcd.setCursor(6,1);
  lcd.print(millis()/1000);
}
