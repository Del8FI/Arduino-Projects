// Moisture Sensor Reading with LCD Display

#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

// Define pin numbers for LCD connection
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
}

void loop() {
  // Read analog value from moisture sensor
  int moistval = analogRead(A0);
  moistval = 1024 - moistval; // Convert the analog value to a range from 0 to 1024
  
  // Display moisture value on LCD and serial monitor
  lcd.clear(); // Clear the LCD display
  lcd.setCursor(0, 0); // Set cursor to the first column of the first row
  lcd.print("Moisture value="); // Print label on the LCD
  Serial.print("Moisture value="); // Print label to serial monitor
  lcd.setCursor(0, 1); // Set cursor to the first column of the second row
  lcd.print(moistval); // Print moisture value on the LCD
  Serial.println(moistval); // Print moisture value to serial monitor
  delay(2000); // Wait for 2 seconds before taking the next reading
}
