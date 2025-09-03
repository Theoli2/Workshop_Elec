#define DURATION 250

// const int buttonPin = 8;  // the number of the pushbutton pin
const int redLedPin = 6; 
const int blueLedPin = 5;
const int voltagePin = 7;
const int analogPin = 0;

int redLightValue = 255;
int blueLightValue = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(redLedPin, OUTPUT);
  pinMode(blueLightValue, OUTPUT);
  // digitalWrite(ledPin, HIGH);
  // attachInterrupt(digitalPinToInterrupt(buttonPin), led_button, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  // led_button();
  // morse_42(LED_BUILTIN);

  light();
  
}

void light(){
  int sensorValue = analogRead(A0);
  redLightValue = map(sensorValue, 0, 140, 0, 255);
  blueLightValue = 255 - redLightValue;

  analogWrite(blueLedPin, blueLightValue);
  analogWrite(redLedPin, redLightValue);
  Serial.println(sensorValue);
  delay(1);
}
