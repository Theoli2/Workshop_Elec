#define DURATION 250

const int buttonPin = 2;  // the number of the pushbutton pin
const int ledPin = 7; 

int buttonState = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(ledPin, HIGH);
  attachInterrupt(digitalPinToInterrupt(buttonPin), led_button, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  led_button();
  morse_42(LED_BUILTIN);
}

void led_button(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    digitalWrite(ledPin, HIGH);
  }
  else {
    digitalWrite(ledPin, LOW);
  }
}

void morse_42(int led){
  dot_(led);
  dot_(led);
  dot_(led);
  dot_(led);
  dash_(led);
  delay(DURATION * 2);
  dot_(led);
  dot_(led);
  dash_(led);
  dash_(led);
  dash_(led);
  delay(DURATION * 10);
}

void dot_(int led) {
  digitalWrite(led, HIGH);
  delay(DURATION);
  digitalWrite(led, LOW);
  delay(DURATION);
}

void dash_(int led) {
  digitalWrite(led, HIGH);
  delay(DURATION * 3);
  digitalWrite(led, LOW);
  delay(DURATION);
}
