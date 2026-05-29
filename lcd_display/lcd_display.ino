#include <LiquidCrystal_I2C.h>
#include <TinyDHT.h>

#define SENSOR_PIN 5
#define SENSOR_TYPE DHT11

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
DHT sensor(SENSOR_PIN, SENSOR_TYPE);
int counter = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();
  lcd.backlight();
  sensor.begin();
}
  

void loop()
{
  delay(1000);
  float temp = sensor.readTemperature();    
  Serial.println("sensor:");
  Serial.println((int)&sensor);
  Serial.println("");
  Serial.println("temp:");
  Serial.println(temp);
  Serial.println("");
  lcd.clear();
  lcd.print(temp);
}
