#include "DHT.h"
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x3F, 16, 2);
#include <Wire.h>
#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
}
void loop() {
  delay(2000);
  int h = dht.readHumidity();
  int t = dht.readTemperature();
  Serial.println(h);
  Serial.println(t);
  lcd.setCursor(0,0);
  lcd.print("Humidity: ");
  lcd.print(h);
  lcd.print("%");
  lcd.setCursor(0,1);
  lcd.print("Temperature: ");
  lcd.print(t);
  lcd.println("C");
}
