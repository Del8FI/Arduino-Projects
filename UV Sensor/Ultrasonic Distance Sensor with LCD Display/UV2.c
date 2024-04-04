// Ultrasonic Distance Sensor with LCD Display, Buzzer, and Light Indicator
// This Arduino sketch measures distance using an ultrasonic sensor and displays the value on an LCD. 
// It also triggers a buzzer and activates a light indicator when an object is detected within a certain distance.

#include <LiquidCrystal.h>

// Pin definitions for the LCD
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;
// Define trigger and echo pin numbers
#define ep 9
#define tp 8
// Pin numbers for buzzer and light indicator
int b = 10, l = 11;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

void setup() {
  Serial.begin(9600); // Set baud rate for serial monitor
  lcd.begin(16, 2);   // Initialize LCD with 16 columns and 2 rows
  pinMode(ep, INPUT); // Set echo pin as input
  pinMode(tp, OUTPUT);// Set trigger pin as output
  pinMode(l, OUTPUT); // Set light indicator pin as output
  pinMode(b, OUTPUT); // Set buzzer pin as output
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

  // Check if object is within 20cm
  if (cm <= 20) {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("Object Nearing");
    Serial.println("Object Nearing");
    lcd.setCursor(0, 1);
    lcd.print("at ");
    Serial.println("at ");
    lcd.print(cm);
    Serial.println(cm);
    lcd.print("cm");
    Serial.println("cm");
    digitalWrite(b, HIGH); // Turn on buzzer
    digitalWrite(l, HIGH); // Turn on light indicator
    delay(2000);
  }
  else {
    lcd.clear();
    lcd.setCursor(0, 0);
    lcd.print("OBJECT IS AT");
    Serial.println("OBJECT IS AT");
    lcd.setCursor(0, 1);
    lcd.print(cm);
    Serial.print(cm);
    lcd.print("cm");
    Serial.println("cm");
    digitalWrite(b, LOW);  // Turn off buzzer
    digitalWrite(l, LOW);  // Turn off light indicator
    delay(2000);
  }
}
