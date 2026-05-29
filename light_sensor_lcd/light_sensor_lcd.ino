#include <LiquidCrystal_I2C.h>
#include <TinyDHT.h>

#define SENSOR_PIN A0
#define SENSOR_TYPE DHT11

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

int sensorValue;

void setup()
{
  lcd.init();
  lcd.backlight();
}
  

void loop()
{
  delay(1000);
  float light = analogRead(SENSOR_PIN);
  float mapped_light = map(light, 0, 1023, 0, 100);
  lcd.clear();
  lcd.print(mapped_light);
}
