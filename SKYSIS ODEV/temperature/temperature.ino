#include <LiquidCrystal.h>

#define tmp A0

LiquidCrystal lcd(2,3,10,11,12,13);
int tmpValue;

void setup()
{
  lcd.begin(16,2);
}
void loop()
{
  lcd.setCursor(0,0);
  tmpValue = analogRead(tmp);
  lcd.print("Temp. Value: ");
  lcd.print(tmp);
  delay(500);
}
