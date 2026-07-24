#include <LiquidCrystal.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27,16,2);

const int sensorPin = A0;

void setup()
{
  Serial.begin(9600);

  lcd.init();
  lcd.backlight();

  lcd.setCursor(0,0);
  lcd.print("Temperature");
}

void loop()
{
  int value = analogRead(sensorPin);

  float voltage = value * (5.0 / 1023.0);

  float temperature = voltage * 100;

  lcd.setCursor(0,1);
  lcd.print("Temp:");
  lcd.print(temperature);
  lcd.print((char)223);
  lcd.print("C ");

  Serial.print("Temperature = ");
  Serial.print(temperature);
  Serial.println(" C");

  delay(1000);
}