#include<LiquidCrystal.h> // Including the LiquidCrystal library for using LCD display
int rs=0, en=1, d4=2, d5=3, d6=4, d7=5, ir=8, l=9, s=10; // Assigning pin numbers for LCD connections, IR sensor, LED, and switch
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Initializing the LCD object with pin connections

void setup() {
  // Setting up the initial configuration
  lcd.begin(16, 2); // Initializing the LCD with 16 columns and 2 rows
  pinMode(ir, INPUT); // Setting the IR sensor pin as input
  pinMode(l, OUTPUT); // Setting the LED pin as output
  pinMode(s, INPUT_PULLUP); // Setting the switch pin as input with internal pull-up resistor
}

void loop() {
  // Main code to be executed repeatedly
  if(digitalRead(s) == LOW) { // Check if the switch is pressed
    int irval = digitalRead(ir); // Read the IR sensor value
    if(irval == 0) { // If object is detected by the IR sensor
      lcd.clear(); // Clearing the LCD display
      lcd.setCursor(0, 0); // Setting the cursor to the first column of the first row
      lcd.print("OBJECT DETECTED"); // Displaying message on LCD
      digitalWrite(l, HIGH); // Turning on the LED
      delay(2000); // Delay for 2 seconds
    } else { // If no object is detected by the IR sensor
      lcd.clear(); // Clearing the LCD display
      lcd.setCursor(0, 0); // Setting the cursor to the first column of the first row
      lcd.print("OBJECT NOT DETECTED"); // Displaying message on LCD
      digitalWrite(l, LOW); // Turning off the LED
      delay(2000); // Delay for 2 seconds
    }
  } else { // If the switch is not pressed
    lcd.clear(); // Clearing the LCD display
    digitalWrite(l, LOW); // Turning off the LED
    delay(2000); // Delay for 2 seconds
  }
}
