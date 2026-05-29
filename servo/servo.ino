#include <LiquidCrystal_I2C.h>
#include <TinyDHT.h>
#include <Servo.h>

#define SENSOR_PIN A0
#define SERVO_PIN 8
#define SENSOR_TYPE DHT11

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display
Servo servo;

int sensorValue;
long step = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  servo.attach(8);
}
  

void loop()
{
  delay(100);
  step++;
  float light = analogRead(SENSOR_PIN);
  float mapped_light = map(light, 0, 1023, 0, 100);
  if(step % 10 == 0){
    lcd.clear();
    lcd.print(mapped_light);
  }
  servo.write(mapped_light * 180 / 100);
}
