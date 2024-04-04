// Fire and Object Detection System with LCD Display

#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

// Define pin numbers for LCD connections and sensors
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins
int fir = 8; // Fire sensor pin
int l = 9; // LED pin
int s = 10; // Button pin
int ir = 11; // Object sensor pin

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set pin modes for sensors and LED
  pinMode(ir, INPUT); // Object sensor
  pinMode(fir, INPUT); // Fire sensor
  pinMode(l, OUTPUT); // LED
  pinMode(s, INPUT_PULLUP); // Button
}

void loop() {
  // Check if emergency button is pressed
  if (digitalRead(s) == LOW) {
    // Display emergency message on LCD and turn on LED
    lcd.clear();
    lcd.print("EMERGENCY");
    digitalWrite(l, HIGH);
    delay(2000);
  } else {
    digitalWrite(l, LOW); // Turn off LED
    
    // Check for fire detection
    int firval = digitalRead(fir);
    if (firval == LOW) {
      // Display fire detection message on LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Fire DETECTED");
      delay(2000);
    }
    
    // Check for object detection
    int irval = digitalRead(ir);
    if (irval == LOW) {
      // Display object detection message on LCD
      lcd.clear();
      lcd.setCursor(0, 0);
      lcd.print("Object DETECTED");
      delay(2000);
    } else {
      // Clear LCD after delay if no detection
      lcd.clear();
      delay(2000);
    }
  }
}
