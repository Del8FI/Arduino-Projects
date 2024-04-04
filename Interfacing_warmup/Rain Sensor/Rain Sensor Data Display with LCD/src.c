// Rain Sensor Data Display with LCD

#include <LiquidCrystal.h> // Include the LiquidCrystal library for controlling the LCD
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7; // Define pins for LCD connections

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Initialize the LCD with the defined pins

void setup() {
  Serial.begin(9600); // Initialize serial communication with baud rate 9600
  lcd.begin(16, 2); // Initialize the LCD with 16 columns and 2 rows
}

void loop() {
  int moistval = analogRead(A0); // Read analog input from the rain sensor connected to pin A0
  moistval = 1024 - moistval; // Invert the analog reading to go from 0 to 1024 (assuming the rain sensor outputs high values when dry and low values when wet)

  lcd.clear(); // Clear the LCD screen
  lcd.setCursor(0, 0); // Set the cursor to the first column of the first row
  lcd.print("Rain value="); // Display the label for the rain sensor value on the LCD
  Serial.print("Rain value="); // Print the label for the rain sensor value to the serial monitor
  lcd.setCursor(0, 1); // Set the cursor to the first column of the second row
  lcd.print(moistval); // Display the actual moisture value on the LCD
  Serial.println(moistval); // Print the moisture value to the serial monitor on a new line
  delay(2000); // Delay for 2 seconds before the next reading
}
