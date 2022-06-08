const int relayPin = 2;     // use this pin to drive the transistor
const int timeDelay = 1000;
const int pResistor = A0;

int value;

void setup()
{
  Serial.begin(9600);
  pinMode(relayPin, OUTPUT);  // set pin as an output
}


void loop()                    
{
  int sensorValue = analogRead(A0);
 Serial.println(sensorValue);
  value = analogRead(pResistor);
  
  if (value > 500){
    digitalWrite(relayPin, LOW); 
  }
  
  if (value < 500){
    digitalWrite(relayPin, HIGH);
  }
  
} 
