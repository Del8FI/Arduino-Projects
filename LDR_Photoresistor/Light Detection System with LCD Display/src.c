// Light Detection System with LCD Display

#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

// Define pin numbers for LCD and light sensor connection
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins
int l = A1; // Light sensor pin

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set the light sensor pin as an input
  pinMode(l, INPUT);
}

void loop() {
  // Read analog value from light sensor
  int lv = analogRead(l);
  
  // Display detected light value on LCD and serial monitor
  lcd.clear(); // Clear the LCD display
  lcd.setCursor(0, 0); // Set cursor to the first column of the first row
  lcd.print("Detected value"); // Print label on the LCD
  Serial.print("Detected value"); // Print label to serial monitor
  lcd.setCursor(0, 1); // Set cursor to the first column of the second row
  lcd.print(lv); // Print light value on the LCD
  Serial.println(lv); // Print light value to serial monitor
  delay(2000); // Wait for 2 seconds before taking the next reading
}
