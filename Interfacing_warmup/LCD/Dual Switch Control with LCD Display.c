#include <LiquidCrystal.h> // Including the LiquidCrystal library for interfacing with LCD
int rs = 0, en = 1, d4 = 2, d5 = 3, d6 = 4, d7 = 5, s2 = 10, s = 11, l2 = 12, l = 13; // Defining pin numbers for LCD, switches, and lights
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Creating an instance of the LiquidCrystal library

void setup() {
  // put your setup code here, to run once:
  pinMode(l, OUTPUT); // Setting pin 'l' as output to control Light 1
  pinMode(l2, OUTPUT); // Setting pin 'l2' as output to control Light 2
  pinMode(s, INPUT_PULLUP); // Setting pin 's' as input with internal pull-up resistor for Switch 1
  pinMode(s2, INPUT_PULLUP); // Setting pin 's2' as input with internal pull-up resistor for Switch 2
  lcd.begin(16, 2); // Initializing the LCD with 16 columns and 2 rows
}

void loop() {
  // put your main code here, to run repeatedly:
  lcd.clear(); // Clearing the LCD display
  
  // Checking if Switch 1 is pressed
  if (digitalRead(s) == LOW) {
    digitalWrite(l, HIGH); // Turning on Light 1
    lcd.setCursor(5, 0); // Setting the cursor position for Switch 1 message
    lcd.print("Switch 1 ON"); // Displaying Switch 1 status
    lcd.setCursor(6, 1); // Setting the cursor position for Light 1 message
    lcd.print("LIGHT 1 ON"); // Displaying Light 1 status
    delay(2000); // Delay for 2 seconds
    digitalWrite(l, LOW); // Turning off Light 1
    delay(2000); // Delay for 2 seconds
  } 
  // Checking if Switch 2 is pressed
  else if (digitalRead(s2) == LOW) {
    digitalWrite(l2, HIGH); // Turning on Light 2
    lcd.setCursor(5, 0); // Setting the cursor position for Switch 2 message
    lcd.print("Switch 2 ON"); // Displaying Switch 2 status
    lcd.setCursor(6, 1); // Setting the cursor position for Light 2 message
    lcd.print("LIGHT 2 ON"); // Displaying Light 2 status
    delay(2000); // Delay for 2 seconds
    digitalWrite(l2, LOW); // Turning off Light 2
    delay(2000); // Delay for 2 seconds
  }
}
