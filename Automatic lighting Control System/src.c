// Light Detection and Control System

#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7, ld = A1, l = 8; // Define pin numbers for LCD, light sensor, and LED
LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);

  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);

  // Set the light sensor pin as an input and LED pin as an output
  pinMode(ld, INPUT);
  pinMode(l, OUTPUT);
}

void loop() {
  // Read analog value from light sensor
  int lv = analogRead(ld);

  // Check if it's night time based on the light intensity
  if (lv > 1000) {
    // Display night time message on LCD and serial monitor, and turn on LED
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Night Time");
    Serial.println("Night Time");
    lcd.setCursor(0, 1);
    lcd.print("Detected value=");
    lcd.print(lv);
    Serial.println("Detected value=");
    Serial.print(lv);
    digitalWrite(l, HIGH); // Turn on the LED
    delay(2000);
  } else {
    // Display day time message on LCD and serial monitor, and turn off LED
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("DAY Time");
    Serial.println("DAY Time");
    lcd.setCursor(0, 1);
    lcd.print("Detected value=");
    lcd.print(lv);
    Serial.println("Detected value=");
    Serial.print(lv);
    digitalWrite(l, LOW); // Turn off the LED
    delay(2000);
  }
}
