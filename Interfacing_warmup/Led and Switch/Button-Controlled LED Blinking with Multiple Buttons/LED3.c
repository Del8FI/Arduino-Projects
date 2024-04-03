const int buttonPin1 = 2;  // Button pin 1
const int buttonPin2 = 3;  // Button pin 2
const int ledPin1 = 13;    // LED pin 1
const int ledPin2 = 12;    // LED pin 2

void setup() {
  pinMode(buttonPin1, INPUT_PULLUP);  // Set buttonPin1 as input with internal pull-up resistor
  pinMode(buttonPin2, INPUT_PULLUP);  // Set buttonPin2 as input with internal pull-up resistor
  pinMode(ledPin1, OUTPUT);           // Set ledPin1 as output
  pinMode(ledPin2, OUTPUT);           // Set ledPin2 as output
}

void loop() {
  if (digitalRead(buttonPin1) == LOW) {  // If button 1 is pressed
    blinkLED(ledPin1, 10);               // Blink LED 1 ten times
  }

  if (digitalRead(buttonPin2) == LOW) {  // If button 2 is pressed
    blinkLED(ledPin2, 5);                // Blink LED 2 five times
  }
}

void blinkLED(int pin, int times) {
  for (int i = 0; i < times; i++) {
    digitalWrite(pin, HIGH);  // Turn the LED on
    delay(1000);               // Wait for 1 second
    digitalWrite(pin, LOW);   // Turn the LED off
    delay(1000);               // Wait for 1 second
  }
}
