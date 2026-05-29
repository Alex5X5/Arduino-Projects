#include <LiquidCrystal_I2C.h>

#include <TinyDHT.h>

#define SENSOR_PIN 5
#define SENSOR_TYPE DHT11

DHT sensor(SENSOR_PIN, SENSOR_TYPE);


void setup() {
  Serial.begin(9600);

  sensor.begin();
}

void loop() {
  double temp = sensor.readTemperature();
  Serial.println(temp);
  delay(500);
}
