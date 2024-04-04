// Ultrasonic Distance Sensor with LCD Display
// This Arduino sketch measures distance using an ultrasonic sensor and displays the value on an LCD.

#include <LiquidCrystal.h>

// Pin definitions for the LCD
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

// Define trigger and echo pin numbers
#define ep 9
#define tp 8

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600);  // Set baud rate for serial monitor
  lcd.begin(16, 2);    // Initialize LCD with 16 columns and 2 rows
  pinMode(ep, INPUT);  // Set echo pin as input
  pinMode(tp, OUTPUT); // Set trigger pin as output
}

void loop() {
  long du, cm;
  
  // Send trigger pulse to the sensor
  digitalWrite(tp, LOW);
  delayMicroseconds(2);
  digitalWrite(tp, HIGH);
  delayMicroseconds(10);
  digitalWrite(tp, LOW);
  
  // Measure the duration of the echo pulse
  du = pulseIn(ep, HIGH);
  
  // Convert duration to distance in centimeters
  cm = du * 0.034 / 2;
  
  delay(100);
  
  // Display distance value on LCD and serial monitor
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Distance value");
  Serial.println("Distance value");
  lcd.setCursor(0, 1);
  lcd.print(du);
  Serial.print(du);
  lcd.print("=");
  Serial.print("=");
  lcd.print(cm);
  Serial.print(cm);
  lcd.print("cm");
  Serial.println("cm");
  
  delay(2000); // Delay for 2 seconds before next measurement
}
