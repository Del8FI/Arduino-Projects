// Serial Control of LED Lights

char ch; // Variable to store received character
int l = 2, l2 = 3; // Pin numbers for controlling LEDs

void setup() {
  // Initialize serial communication with baud rate 9600
  Serial.begin(9600);
  
  // Set pin modes for LEDs as output
  pinMode(l, OUTPUT);
  pinMode(l2, OUTPUT);
}

void loop() {
  // Check if data is available on the serial port
  if (Serial.available()) {
    // Read the incoming character from the serial port
    ch = Serial.read();
    
    // Print the received character to the serial monitor
    Serial.print("ch=");
    Serial.println(ch);
    delay(1000);

    // Control LEDs based on received character
    if (ch == '1') {
      digitalWrite(l, HIGH); // Turn on LED connected to pin l
      delay(1000); // Wait for 1 second
    } else if (ch == '2') {
      digitalWrite(l, LOW); // Turn off LED connected to pin l
      delay(1000); // Wait for 1 second
    } else if (ch == '3') {
      digitalWrite(l2, HIGH); // Turn on LED connected to pin l2
      delay(1000); // Wait for 1 second
    } else if (ch == '4') {
      digitalWrite(l2, LOW); // Turn off LED connected to pin l2
      delay(1000); // Wait for 1 second
    }
  }
}
