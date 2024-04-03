#include <LiquidCrystal.h>   // Including the LiquidCrystal library for interfacing with LCD
int rs=0, en=1, d4=2, d5=3, d6=4, d7=5, s2=10, s=11, l2=12, l=13; // Assigning pin numbers for LCD and push buttons
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);   // Creating an LCD object with specified pin connections

void setup() {
  pinMode(l, OUTPUT);    // Setting pin l as output (presumably for controlling something)
  pinMode(l2, OUTPUT);   // Setting pin l2 as output (presumably for controlling something)
  pinMode(s, INPUT_PULLUP);   // Setting pin s as input with internal pull-up resistor enabled
  pinMode(s2, INPUT_PULLUP);  // Setting pin s2 as input with internal pull-up resistor enabled
  lcd.begin(16, 2);   // Initializing the LCD with 16 columns and 2 rows
}

void loop() {
  lcd.clear();    // Clearing the LCD display
  lcd.setCursor(0, 0);   // Setting the cursor to the first column of the first row
  lcd.print("JOHAN");    // Printing "JOHAN" on the LCD
  lcd.setCursor(0, 1);   // Setting the cursor to the first column of the second row
  lcd.print("1JP2123");   // Printing "1JP2123" on the LCD
  delay(2000);    // Delaying for 2 seconds

  lcd.clear();    // Clearing the LCD display
  lcd.print("RAN");    // Printing "RAN" on the LCD
  lcd.setCursor(0, 1);   // Setting the cursor to the first column of the second row
  lcd.print("1JP2423");   // Printing "1JP2423" on the LCD
  delay(2000);    // Delaying for 2 seconds

  lcd.clear();    // Clearing the LCD display
  lcd.print("KIYO");    // Printing "KIYO" on the LCD
  lcd.setCursor(0, 1);   // Setting the cursor to the first column of the second row
  lcd.print("1JP2223");   // Printing "1JP2223" on the LCD
  delay(2000);    // Delaying for 2 seconds
}
