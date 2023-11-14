// LM35 Temperature Sensor interface with Arduino Uno

const int LM35_PIN = A0;  // LM35 sensor connected to analog pin A0
const int LED_PIN = 13;   // Onboard LED connected to digital pin 13

// Function to read temperature from LM35 sensor
float readTemperature() {
  int sensorValue = analogRead(LM35_PIN);
  float voltage = (sensorValue / 1024.0) * 5.0;
  float temperature = (voltage - 0.5) * 100.0;
  return temperature;
}

void setup() {
  pinMode(LED_PIN, OUTPUT);  // Set LED pin as OUTPUT
}

void loop() {
  float currentTemperature = readTemperature();

  if (currentTemperature < 30.0) {
    // Temperature below 30 degrees Celsius
    digitalWrite(LED_PIN, HIGH);  // Turn on LED
    delay(250);                    // Wait for 250 milliseconds
    digitalWrite(LED_PIN, LOW);   // Turn off LED
    delay(250);                    // Wait for 250 milliseconds
  } else {
    // Temperature above or equal to 30 degrees Celsius
    digitalWrite(LED_PIN, HIGH);  // Turn on LED
    delay(500);                    // Wait for 500 milliseconds
    digitalWrite(LED_PIN, LOW);   // Turn off LED
    delay(500);                    // Wait for 500 milliseconds
  }
}
