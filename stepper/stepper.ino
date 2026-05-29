#include <LiquidCrystal_I2C.h>
#include <TinyDHT.h>
#include <Stepper.h>

#define SENSOR_PIN A0
#define stepper_PIN 8
#define SENSOR_TYPE DHT11

#define SPU 2048

LiquidCrystal_I2C lcd(0x27,20,4);  // set the LCD address to 0x27 for a 16 chars and 2 line display

Stepper motor(SPU, 3, 5, 4, 6);

int sensorValue;
long step = 0;

void setup()
{
  lcd.init();
  lcd.backlight();
  motor.setSpeed(5);
}
  

void loop()
{
  delay(100);
  motor.step(-100);
  //step++;
  //float light = analogRead(SENSOR_PIN);
  //float mapped_light = map(light, 0, 1023, 0, 100);
  //if(step % 10 == 0){
  //  lcd.clear();
  //  lcd.print(mapped_light);
  //}
  //stepper.write(mapped_light * 180 / 100);
}
