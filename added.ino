#include <DHT.h>
#define DHTPIN 2 
#define DHTTYPE DHT22 
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
DHT dht(DHTPIN, DHTTYPE);
 
LiquidCrystal_I2C lcd(0x27,16,2);
float hum; 
float temp; 
 
void setup() {
  Serial.begin(9600);
  dht.begin();
  delay(2000);
  lcd.begin();
  lcd.backlight();
  lcd.setCursor(2,0);
  delay(5000);
  lcd.clear();
}
 
void loop() {
  hum = dht.readHumidity();
  temp= dht.readTemperature();
 
  Serial.print("HUMIDITY: ");
  Serial.print(hum,0);
  Serial.print(" %, TEMPERATURE: ");
  Serial.print(temp, 1);
  Serial.println(" C");
  lcd.setCursor(0,0);
  lcd.print("TEMP:");
 
  float t = temp;
  lcd.print(t,1);
  lcd.print(" C");
  lcd.setCursor(0,1);
  lcd.print("HUMIDITY:");
  int h = hum;
  lcd.print(h);
  lcd.print(" % ");
  lcd.println();
  if(t > 32 && h > 70){
     lcd.setCursor(14,0);
     lcd.print("X");
  }
  else{
    lcd.setCursor(14,0);
     lcd.print("O");
  }
  delay(2000);
}
