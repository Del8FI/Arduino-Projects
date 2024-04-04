// Temperature and Humidity Monitoring with DHT11 Sensor and LCD Display
// This Arduino sketch reads temperature and humidity values from a DHT11 sensor and displays them on an LCD.

#include <LiquidCrystal.h>
#include <DHT.h> // Include DHT library

#define DHT_pin 8  // Define pin for DHT sensor
#define Type DHT11  // Define type of DHT sensor

DHT HT(DHT_pin, Type); // Initialize DHT sensor object

float t, h; // Variables to store temperature and humidity values

// Pin definitions for the LCD
int rs = 2, en = 3, d4 = 4, d5 = 5, d6 = 6, d7 = 7;

LiquidCrystal lcd(rs, en, d4, d5, d6, d7); // Initialize LCD object

void setup() {
  HT.begin(); // Initialize DHT sensor
  lcd.begin(16, 2); // Initialize LCD with 16 columns and 2 rows
  pinMode(DHT_pin, INPUT); // Set DHT pin as input
}

void loop() {
  // Read temperature and humidity values from DHT sensor
  t = HT.readTemperature();
  h = HT.readHumidity();
  
  // Display temperature and humidity values on LCD
  lcd.clear();
  lcd.setCursor(0, 0);
  lcd.print("Temperature=");
  lcd.print(t);
  lcd.setCursor(0, 1);
  lcd.print("Humidity=");
  lcd.print(h);
  
  delay(2000); // Delay for 2 seconds before next reading
}
