/* SparkFun Inventor's Kit 
Example sketch 02

POTENTIOMETER

  Measure the position of a potentiometer and use it to
  control the blink rate of an LED. Turn the knob to make
  it blink faster or slower!

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about Arduino.
*/



//Create global variables (variables that can be used anywhere in our sketch)

// Here we're creating a variable called "sensorPin" of type "int"
// and initializing it to have the value "0," which is the analog input pin the pot is     //conected to.
int sensorPin = 0;    

// Variable for storing the pin number that the LED is connected to                 
int ledPin1 = 13;      
int ledPin2 = 12;     
int ledPin3 = 11;     
// this function runs once when the sketch starts up
void setup() 
{
   Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);

}

// this function runs repeatedly after setup() finishes
void loop() {
  // read the input on analog pin 0:
  int sensorValue = analogRead(A0);
  sensorValue= map(sensorValue,0,1023,0,8);

if (sensorValue >= 0 && sensorValue <= 1023) {
    digitalWrite(13, (sensorValue & 1));
    digitalWrite(12, (sensorValue & 2));
    digitalWrite(11, (sensorValue & 4));
   }
   Serial.println(sensorValue);
   delay(1000);
  // print out the value you read:
  digitalWrite(13, HIGH);     // Turn the LED on

  delay(sensorValue);             

  digitalWrite(13, LOW);      // Turn the LED off

  delay(sensorValue);             
  Serial.println(sensorValue);
  delay(1);        // delay in between reads for stability*/
}
