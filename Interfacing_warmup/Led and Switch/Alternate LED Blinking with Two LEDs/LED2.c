int l = 13;   // Define variable 'l' and assign pin number 13 to it
int l2 = 12;  // Define variable 'l2' and assign pin number 12 to it
int i;        // Declare variable 'i'

void setup() {
  pinMode(l, OUTPUT);  // Set pin 13 (l) as output
  pinMode(l2, OUTPUT); // Set pin 12 (l2) as output
}

void loop() {
  // Blinking the LED connected to pin 13 (l)
  for (i = 1; i <= 10; i++) {
    digitalWrite(l, HIGH); // Turn on the LED connected to pin 13 (l)
    delay(2000);           // Wait for 2 seconds
    digitalWrite(l, LOW);  // Turn off the LED connected to pin 13 (l)
    delay(2000);           // Wait for 2 seconds
  }

  // Blinking the LED connected to pin 12 (l2)
  for (i = 0; i < 10; i++) {
    digitalWrite(l2, HIGH); // Turn on the LED connected to pin 12 (l2)
    delay(2000);            // Wait for 2 seconds
    digitalWrite(l2, LOW);  // Turn off the LED connected to pin 12 (l2)
    delay(2000);            // Wait for 2 seconds
  }
}
