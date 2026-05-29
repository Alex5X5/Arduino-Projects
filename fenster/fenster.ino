#include "scheduler.h"
#include <LiquidCrystal_I2C.h>
#include <TinyDHT.h>

#define DHT_PIN 11
#define LIGHT_SENSOR_PIN A0
#define SENSOR_TYPE DHT11

#define LED_PIN_RED 8
#define LED_PIN_BLUE 10
#define LED_PIN_GREEN 9

Scheduler scheduler;
LiquidCrystal_I2C lcd(0x27,20,4);
DHT sensor(DHT_PIN, SENSOR_TYPE);

float mappedLight = 0;
float temp = 0;
bool windowOpen = false;

void setup()
{
  Serial.begin(9600);
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_BLUE, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
  lcd.init();
  lcd.backlight();
  sensor.begin();
  scheduler.scheduleAt(dhtLoop, 1);
  scheduler.scheduleAt(lightLoop, 1);
  scheduler.scheduleAt(lcdUpdate, 5);
}
  
void loop()
{
  delay(1);
  scheduler.tick();
}

void dhtLoop(long tick){
  temp = sensor.readTemperature();
  scheduler.scheduleIn(dhtLoop, 1000);
}

void lightLoop(long tick) {
  float light = analogRead(LIGHT_SENSOR_PIN);
  mappedLight = map(light, 0, 1023, 0, 100);
  if(mappedLight>50){
    digitalWrite(LED_PIN_GREEN, HIGH); // grün
    digitalWrite(LED_PIN_RED, LOW); // grün
  } else {
    digitalWrite(LED_PIN_GREEN, LOW); // grün
    digitalWrite(LED_PIN_RED, HIGH); // grün 
  }
  scheduler.scheduleIn(lightLoop, 10);
}

void lcdUpdate(long tick){
  lcd.clear();
  lcd.setCursor(0, 1);
  

}
