#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

// Define pin numbers for LCD connection and gas sensor
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins
int g = A1; // Gas sensor pin

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set pin mode for gas sensor
  pinMode(g, INPUT);
}

void loop() {
  // Read analog value from gas sensor
  int gv = analogRead(g);
  
  // Display gas sensor reading on LCD and serial monitor
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Gas value=");
  Serial.print("Gas value=");
  lcd.setCursor(0, 1);
  lcd.print(gv);
  Serial.println(gv); // Print gas sensor reading to serial monitor
  delay(2000); // Wait for 2 seconds before taking next reading
}
