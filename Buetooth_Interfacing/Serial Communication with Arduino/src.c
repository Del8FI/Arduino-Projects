// Serial Communication with Arduino

char ch; // Variable to store received character

void setup() {
  // Initialize serial communication with baud rate 9600
  Serial.begin(9600);
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available()) {
    // Read the incoming character from the serial port
    ch = Serial.read();
    
    // Print the received character to the serial monitor
    Serial.print("ch=");
    Serial.println(ch);
    
    // Delay for 1 second
    delay(1000);
  }
}
