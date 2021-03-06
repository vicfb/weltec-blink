#include <Arduino.h>
#define ledPin 21
#define button 14


// constants won't change. Used here to set a pin number:
// the number of the LED pin

// Variables will change:
int ledState = LOW;             // ledState used to set the LED
int buttonState; 
int previousButtonState;
int buttonCount;


// Generally, you should use "unsigned long" for variables that hold time
// The value will quickly become too large for an int to store
unsigned long previousMillis = 0;        // will store last time LED was updated

// constants won't change:
const long interval = 1000;           // interval at which to blink (milliseconds)

void setup() {
  // set the digital pin as output:
  pinMode(ledPin, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  Serial.begin(115200);
}

void loop() {
  // here is where you'd put code that needs to be running all the time.
  // check to see if it's time to blink the LED; that is, if the difference
  // between the current time and last time you blinked the LED is bigger than
  // the interval at which you want to blink the LED.
  unsigned long currentMillis = millis();

  previousButtonState = buttonState;
  buttonState = digitalRead(button);
  if (previousButtonState == HIGH && buttonState == LOW){
    buttonCount++;
    Serial.println(buttonCount);
  }
  
  
  if(buttonState==LOW){
      if (currentMillis - previousMillis >= interval) {
        // save the last time you blinked the LED
        previousMillis = currentMillis;

        // if the LED is off turn it on and vice-versa:
        if (ledState == LOW) {
        ledState = HIGH;
        } else {
        ledState = LOW;
        }

        // set the LED with the ledState of the variable:
        digitalWrite(ledPin, ledState);
    }
  }
  else{
      digitalWrite(ledPin, LOW);
  }
  
}