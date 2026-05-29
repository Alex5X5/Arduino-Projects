#include <Thermistor.h>
#include <NTC_Thermistor.h>

#define SENSOR_PIN 0
#define Referenzwiderstand 10000
#define Nominalwiderstand 10000
#define Nominaltemperatur 25
#define BWert 3950

Thermistor* thermistor;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  thermistor = new NTC_Thermistor(SENSOR_PIN, Referenzwiderstand, Nominalwiderstand, Nominaltemperatur, BWert);

}

void loop() {
  // put your main code here, to run repeatedly:
  Serial.println( thermistor -> readCelsius());
  delay(1000);
}
