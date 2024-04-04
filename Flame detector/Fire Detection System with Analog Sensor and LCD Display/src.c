// Fire Detection System with Analog Sensor and LCD Display

#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD
// Define pin numbers for LCD connections
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
int fir = 8; // Define pin number for analog sensor

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set pin mode for the analog sensor as input
  pinMode(fir, INPUT);
}

void loop() {
  // Read analog value from the sensor
  int firval = analogRead(fir);
  
  // Display sensor value on LCD
  lcd.clear(); // Clear the LCD display
  lcd.setCursor(0, 0); // Set the cursor position to the first column of the first row
  lcd.print("FIR VALUE"); // Print text "FIR VALUE" on the LCD
  lcd.setCursor(0, 1); // Set the cursor position to the first column of the second row
  lcd.print(firval); // Print the analog sensor value on the LCD
  
  // Delay for 2 seconds
  delay(2000);
}
