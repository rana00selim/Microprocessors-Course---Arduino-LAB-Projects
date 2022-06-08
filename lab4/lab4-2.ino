const int temperaturePin = 0;
const int sensorPin = 1;
const int ledPin = 9;

int lightLevel, high = 0, low = 1023;

void setup()
{
  Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}


void loop()
{
int sensorValue = analogRead(A1);
 Serial.println(sensorValue);
  lightLevel = analogRead(sensorPin);

  
  analogWrite(ledPin, lightLevel);
  
  float voltage, degreesC, degreesF;

  voltage = getVoltage(temperaturePin);
  degreesC = (voltage - 0.5) * 100.0;
  degreesF = degreesC * (9.0/5.0) + 32.0;
  Serial.print("voltage: ");
  Serial.print(voltage);
  Serial.print("  deg C: ");
  Serial.print(degreesC);
  Serial.print("  deg F: ");
  Serial.println(degreesF);
  delay(500);
    manualTune();
}

void manualTune()
{
  lightLevel = map(lightLevel, 45, 342, 0, 255);
  lightLevel = constrain(lightLevel, 0, 255);
} 

float getVoltage(int pin)
{
  return (analogRead(pin) * 0.004882814);
}
