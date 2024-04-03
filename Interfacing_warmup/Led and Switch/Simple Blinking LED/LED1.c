int LED=13; // Define variable 'LED' and assign pin number 13 to it

void setup()
{
  pinMode(LED, OUTPUT); // Set pin 13 (LED) as output
}

void loop()
{
  digitalWrite(LED, HIGH); // Turn on the LED
  delay(1000); // Wait for 1 second (1000 milliseconds)
  digitalWrite(LED, LOW); // Turn off the LED
  delay(1000); // Wait for 1 second (1000 milliseconds)
}
