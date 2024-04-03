#include <LiquidCrystal.h> // Include the LiquidCrystal library

// Define pin numbers for LCD connections
int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5, s2 = 10, s = 11, l2 = 12, l = 13;

// Create an instance of LiquidCrystal library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set pin modes for switches and lights
  pinMode(l, OUTPUT); // Initialize pin for Light 1
  pinMode(l2, OUTPUT); // Initialize pin for Light 2
  pinMode(s, INPUT_PULLUP); // Set pin for Switch 1 as input with internal pull-up resistor
  pinMode(s2, INPUT_PULLUP); // Set pin for Switch 2 as input with internal pull-up resistor
  
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
}

void loop() {
  // Clear the LCD screen
  lcd.clear();
  
  // Check if Switch 1 is pressed
  if (digitalRead(s) == LOW) {
    // Turn on Light 1
    digitalWrite(l, HIGH);
    // Print messages on LCD
    lcd.print("Switch 1 ON");
    lcd.setCursor(0, 1);
    lcd.print("LIGHT 1 ON");
    // Delay for 2 seconds
    delay(2000);
    // Turn off Light 1
    digitalWrite(l, LOW);
    // Delay for 2 seconds
    delay(2000);
  }
  // Check if Switch 2 is pressed
  else if (digitalRead(s2) == LOW) {
    // Turn on Light 2
    digitalWrite(l2, HIGH);
    // Print messages on LCD
    lcd.print("Switch 2 ON");
    lcd.setCursor(0, 1);
    lcd.print("LIGHT 2 ON");
    // Delay for 2 seconds
    delay(2000);
    // Turn off Light 2
    digitalWrite(l2, LOW);
    // Delay for 2 seconds
    delay(2000);
  }
}
