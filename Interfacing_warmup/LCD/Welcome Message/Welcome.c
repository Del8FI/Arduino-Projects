// LCD Welcome Message

#include <LiquidCrystal.h>

// Define the pin connections to the LCD
int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  // Initialize the LCD with 16 columns and 2 rows
  lcd.begin(16, 2);
}

void loop() {
  // Clear the LCD screen
  lcd.clear();
  
  // Print "WELCOME" on the first line
  lcd.print("WELCOME");
  
  // Set the cursor to the beginning of the second line
  lcd.setCursor(0, 1);
  
  // Print "To My World" on the second line
  lcd.print("To My World");
  
  // Delay for 2 seconds
  delay(2000);
}
