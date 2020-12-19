#include "DHT.h"
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#define DHTPIN 5
#define DHTTYPE DHT11   // DHT 11

DHT dht(DHTPIN, DHTTYPE);
LiquidCrystal_I2C lcd(0x27, 16, 2); // set the LCD address to 0x27 for a 16 chars and 2 line display

void setup() {
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  lcd.setCursor(0, 0); //(row,column)
  lcd.print("Hello, world!");
  lcd.setCursor(0, 1);
  lcd.print("DHT11 test!");
  dht.begin();

}

void loop() {
  delay(2000);
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t) ) {
    Serial.println(F("Failed to read from DHT sensor!"));
    return;
  }
  lcd.setCursor(0, 0); //(row,column)
  lcd.print("Humidity: ");
  lcd.setCursor(10, 0);
  lcd.print(h);
  lcd.setCursor(12, 0);
  lcd.print(" %  ");

  lcd.setCursor(0, 1); //(row,column)
  lcd.print("Temperature:");
  lcd.setCursor(12, 1);
  lcd.print(t);
  lcd.setCursor(14, 1);
  lcd.print(" C ");

}
