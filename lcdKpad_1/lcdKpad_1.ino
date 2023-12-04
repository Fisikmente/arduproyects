#include <LiquidCrystal.h>

LiquidCrystal lcd(8, 9, 4, 5, 6, 7);

int dt1 = 600;
int dt1 = 2500;

void setup() {
  lcd.begin(16, 2);

}

void loop() {
  for (int i=0; i<6; i++) {
    lcd.setCursor(2,0);
    lcd.print("INGENIO TOTAL");
    lcd.setCursor(2,1);
    lcd.print("QUE CUENTAS :D");
    delay(dt1);
    lcd.clear();
    delay(dt1/2);

    lcd.setCursor(1,0);
    lcd.print("Recuerda");
    lcd.setCursor(3,1);
    lcd.print("Suscribirte");
    delay(dt1);
    lcd.clear();
  }
}
