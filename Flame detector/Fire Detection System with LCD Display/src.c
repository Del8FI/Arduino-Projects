// Fire Detection System with LCD Display

#include <LiquidCrystal.h>

// Pin definitions
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins
int fir = 8; // Fire sensor pin
int l = 9; // LED pin
int s = 10; // Button pin

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize LCD display
  lcd.begin(16, 2);
  
  // Set pin modes
  pinMode(fir, INPUT);
  pinMode(l, OUTPUT);
  pinMode(s, INPUT_PULLUP); // Internal pull-up resistor for button
}

void loop() {
  // Check if fire sensor is triggered
  int firval = digitalRead(fir);
  
  // Check if button is pressed
  if (digitalRead(s) == LOW) {
    // Display message and turn off LED
    lcd.clear();
    digitalWrite(l, LOW);
    delay(2000);
  } else {
    // Display fire detection status and control LED accordingly
    lcd.clear();
    lcd.setCursor(0, 0);
    if (firval == 0) {
      lcd.print("Fire DETECTED");
      digitalWrite(l, HIGH); // Turn on LED
    } else {
      lcd.print("NO Fire DETECTED");
      digitalWrite(l, LOW); // Turn off LED
    }
    delay(2000);
  }
}
