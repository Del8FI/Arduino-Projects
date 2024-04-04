// Infrared Sensor Reading

#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

// Define pin numbers for LCD and infrared sensor
int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5, ir = 8;

// Create an instance of the LiquidCrystal library
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set the infrared sensor pin as an input
  pinMode(ir, INPUT);
}

void loop() {
  // Read digital value from the infrared sensor
  int irval = digitalRead(ir);
  
  // Clear the LCD display
  lcd.clear();
  
  // Set cursor to the first column of the first row
  lcd.setCursor(0, 0);
  
  // Display "IR VALUE" on the LCD
  lcd.print("IR VALUE");
  
  // Set cursor to the first column of the second row
  lcd.setCursor(0, 1);
  
  // Display the digital value read from the infrared sensor on the LCD
  lcd.print(irval);
  
  // Delay for 2 seconds
  delay(2000);
}
