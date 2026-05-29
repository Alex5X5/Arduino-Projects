#define LED_PIN_RED 6
#define LED_PIN_BLUE 3
#define LED_PIN_GREEN 5
#define RPM_HIGH 255
#define RPM_LOW 0
#define FADE_STEP 5

int brightnessRed = 0;
int brightnessGreen = 0;
int brightnessBlue = 0;


int buttonState = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  // put your setup code here, to run once:
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_BLUE, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
}

void fadeTo(int pin, int targetBrightness, int* brightness){
  int fade = *brightness < targetBrightness ? FADE_STEP : -FADE_STEP;
  Serial.println(targetBrightness);
  Serial.println((int)brightness);
  Serial.println(fade);
  for(int i=0; i<40; i++){
    *brightness = *brightness + fade;
    //Serial.println(*brightness);
    analogWrite(pin, *brightness);
    delay(10);
  }
}

void loop() {
  fadeTo(LED_PIN_BLUE, RPM_HIGH, &brightnessBlue); // rot gelb
  delay(1000);
  fadeTo(LED_PIN_BLUE, RPM_LOW, &brightnessBlue);
  delay(1000);
  fadeTo(LED_PIN_RED, RPM_HIGH, &brightnessRed); // grün
  delay(1000);
  fadeTo(LED_PIN_RED, RPM_LOW, &brightnessRed);
  delay(1000);
  fadeTo(LED_PIN_GREEN, RPM_HIGH, &brightnessGreen); // gelb
  delay(1000);
  fadeTo(LED_PIN_GREEN, RPM_LOW, &brightnessGreen);
  delay(1000);
}
