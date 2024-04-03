#include <LiquidCrystal.h> // Include the LiquidCrystal library for controlling the LCD

// Define variables for LCD pin connections
int rs = 13, en = 12, d4 = 5, d5 = 6, d6 = 7, d7 = 8;

// Define the pin for the push-button switch
int sw1 = 2;

// Initialize the LCD object with pin connections
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Set the push-button switch pin as input with a built-in pull-up resistor
  pinMode(sw1, INPUT_PULLUP);

  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Clear any previous content on the LCD
  lcd.clear();

  // Print the character 'A' on the LCD
  lcd.print('A');

  // Delay for 1 second
  delay(1000);
}

void loop() {
  // Check if the push-button switch is pressed (reads LOW)
  if (digitalRead(sw1) == LOW) {
    // Clear the display
    lcd.clear();

    // Set the cursor to the first column of the first row
    lcd.setCursor(0, 0);

    // Print the string "ABC" starting from the current cursor position
    lcd.print("ABC");

    // Set the cursor to the first column of the second row
    lcd.setCursor(0, 1);

    // Print the string "XYZ" starting from the current cursor position
    lcd.print("XYZ");

    // Delay for 2 seconds
    delay(2000);
  }
}
