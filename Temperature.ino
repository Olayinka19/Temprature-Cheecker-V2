int tempPin = 0;
int led1 = 9; // Assign LED pins
int led2 = 10;
int led3 = 11;

void setup()
{
  Serial.begin(9600);
  pinMode(led1, OUTPUT); // Set LED pins as output
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
}

void loop()
{
  double tempK = getTempInKelvin(tempPin);
  float tempC = tempK - 273.15;            // Convert Kelvin to Celsius
  float tempF = (tempC * 9.0) / 5.0 + 32.0; // Convert Celsius to Fahrenheit

  // Display Temperature
  Serial.print("Temp       ");
  Serial.print(tempF);
  Serial.print("F       ");
  Serial.print(tempC);
  Serial.println("C");

  // Control LEDs based on temperature
  if (tempC < 20) {
    // No LEDs
    digitalWrite(led1, LOW);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (tempC >= 22 && tempC <= 23) {
    // 1 LED
    digitalWrite(led1, HIGH);
    digitalWrite(led2, LOW);
    digitalWrite(led3, LOW);
  } else if (tempC >= 24 && tempC <= 25) {
    // 2 LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, LOW);
  } else if (tempC >= 26) {
    // 3 LEDs
    digitalWrite(led1, HIGH);
    digitalWrite(led2, HIGH);
    digitalWrite(led3, HIGH);
  }

  delay(500);
}

double getTempInKelvin(int pin)
{
  int tempReading = analogRead(pin);
  double tempK = log(10000.0 * ((1024.0 / tempReading - 1)));
  tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * tempK * tempK )) * tempK );       //  Temp Kelvin

  return tempK;
}