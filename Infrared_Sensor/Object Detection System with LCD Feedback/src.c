#include <LiquidCrystal.h>

// Define the pin numbers for the LCD
int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
// Define the pin numbers for the IR sensor and LED
int ir = 8, l = 9;

// Create an LCD object
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set the IR pin as input and LED pin as output
  pinMode(ir, INPUT);
  pinMode(l, OUTPUT);
}

void loop() {
  // Read the state of the IR sensor
  int irval = digitalRead(ir);
  
  // Check if an object is detected
  if (irval == 0) {
    // Clear the LCD display
    lcd.clear();
    // Set the cursor to the first column of the first row
    lcd.setCursor(0, 0);
    // Display message indicating object detection
    lcd.print("OBJECT DETECTED");
    // Turn on the LED
    digitalWrite(l, HIGH);
    // Delay for 2 seconds
    delay(2000);
  } else {
    // Clear the LCD display
    lcd.clear();
    // Set the cursor to the first column of the first row
    lcd.setCursor(0, 0);
    // Display message indicating no object detected
    lcd.print("OBJECT NOT DETECTED");
    // Turn off the LED
    digitalWrite(l, LOW);
    // Delay for 2 seconds
    delay(2000);
  }
}
