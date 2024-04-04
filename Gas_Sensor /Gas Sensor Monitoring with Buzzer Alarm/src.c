#include <LiquidCrystal.h> // Include the LiquidCrystal library for interfacing with LCD

// Define pin numbers for LCD connection, gas sensor, and buzzer
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // LCD pins
int g = A1; // Gas sensor pin
int b = 8; // Buzzer pin

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Create an instance of the LiquidCrystal library

void setup() {
  // Initialize serial communication for debugging
  Serial.begin(9600);
  
  // Initialize LCD display with 16 columns and 2 rows
  lcd.begin(16, 2);
  
  // Set pin modes for gas sensor and buzzer
  pinMode(g, INPUT);
  pinMode(b, OUTPUT);
}

void loop() {
  // Read analog value from gas sensor
  int gv = analogRead(g);
  
  // Check if gas level is above threshold
  if (gv > 500) {
    // Display danger message on LCD and activate buzzer alarm
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Danger!!");
    Serial.println("Danger!!");
    lcd.setCursor(0, 1);
    lcd.print("Gas value=");
    lcd.print(gv);
    Serial.print("Gas value=");
    Serial.println(gv);
    digitalWrite(b, HIGH); // Turn on buzzer
    delay(2000); // Wait for 2 seconds
  } else {
    // Display normal message on LCD and deactivate buzzer alarm
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.println("NORMAL");
    Serial.println("NORMAL");
    lcd.setCursor(0, 1);
    lcd.print("Gas value=");
    lcd.print(gv);
    Serial.print("Gas value=");
    Serial.println(gv);
    digitalWrite(b, LOW); // Turn off buzzer
    delay(2000); // Wait for 2 seconds
  }
}
