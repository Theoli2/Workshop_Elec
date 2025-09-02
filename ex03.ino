#define DURATION 250

const int buttonPin = 8;  // the number of the pushbutton pin
const int ledPin = 3; 

int buttonState = 0;
int lightValue = 255;  

void setup() {
  // put your setup code here, to run once:
  pinMode(buttonPin, INPUT_PULLUP);
  pinMode(ledPin, OUTPUT);
  pinMode(LED_BUILTIN, OUTPUT);
  // digitalWrite(ledPin, HIGH);
  // attachInterrupt(digitalPinToInterrupt(buttonPin), led_button, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  // led_button();
  // morse_42(LED_BUILTIN);
  sunlight();
}

void sunlight(){
  buttonState = digitalRead(buttonPin);
  if (buttonState == HIGH)
  {
    while (lightValue < 255)
    {
      analogWrite(ledPin, lightValue);
      delay(2);
      lightValue++;
    }
  }
  else {
    while (lightValue > 0)
    {
      analogWrite(ledPin, lightValue);
      delay(2);
      lightValue--;
    }
  }
}
