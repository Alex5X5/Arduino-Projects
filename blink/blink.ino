#define LED_PIN_RED 13
#define LED_PIN_YELLOW 12
#define LED_PIN_GREEN 11
#define CHANGE 1

int brightness;
int fade = 5;


int buttonState = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("Setup");
  // put your setup code here, to run once:
  pinMode(LED_PIN_RED, OUTPUT);
  pinMode(LED_PIN_YELLOW, OUTPUT);
  pinMode(LED_PIN_GREEN, OUTPUT);
}

void fadeTo(int pin, int targetBrightness){
  for(int i=0; i<40; i++){
    brightness += fade;
    Serial.println(brightness);
    analogWrite(pin, brightness);
    delay(10);
  }
  fade = -fade;
}

void loop() {
  digitalWrite(LED_PIN_YELLOW, HIGH); // rot gelb
  delay(600);
  digitalWrite(LED_PIN_RED, LOW); // grün
  digitalWrite(LED_PIN_YELLOW, LOW);
  digitalWrite(LED_PIN_GREEN, HIGH);
  delay(500);
  digitalWrite(LED_PIN_GREEN, LOW); // gelb
  digitalWrite(LED_PIN_YELLOW, HIGH);
  delay(600);
  digitalWrite(LED_PIN_YELLOW, LOW); // rot
  digitalWrite(LED_PIN_RED, HIGH);
  delay(5000);
}
