
#include <Servo.h> 

Servo servo1;

const int button1Pin = 2;  // pushbutton 1 pin
const int button2Pin = 3;  // pushbutton 2 pin
const int ledPin1 =  13;
const int ledPin2 =  12;
const int ledPin3 =  11;// LED pin

int button1State, button2State;  // variables to hold the pushbutton states

// Define the analog input pin to measure flex sensor position:

const int flexpin = 0; 


void setup() 
{ 
  // Use the serial monitor window to help debug our sketch:

  Serial.begin(9600);

  // Enable control of a servo on pin 9:

  servo1.attach(9);
  pinMode(button1Pin, INPUT);//increase
  pinMode(button2Pin, INPUT);//decrease

  // Set up the LED pin to be an output:
  pinMode(ledPin1, OUTPUT); //slow    
    pinMode(ledPin2, OUTPUT); //normal
      pinMode(ledPin3, OUTPUT); //fast
} 


void loop() 
{ 
  static int position;
  int flexposition;    // Input value from the analog pin.
  int servoposition;   // Output value to the servo.

  // Read the position of the flex sensor (0 to 1023):

  flexposition = analogRead(flexpin);

  // Because the voltage divider circuit only returns a portion
  // of the 0-1023 range of analogRead(), we'll map() that range
  // to the servo's range of 0 to 180 degrees. The flex sensors
  // we use are usually in the 600-900 range:

  servoposition = map(flexposition, 700, 980, 0, 180);
  servoposition = constrain(servoposition, 0, 180);

  // Now we'll command the servo to move to that position:

  servo1.write(servoposition);

  // Because every flex sensor has a slightly different resistance,
  // the 600-900 range may not exactly cover the flex sensor's
  // output. To help tune our program, we'll use the serial port to
  // print out our values to the serial monitor window:

  Serial.print("sensor: ");
  Serial.print(flexposition);
  Serial.print("  servo: ");
  Serial.println(servoposition);
  delay(150);

  // Note that all of the above lines are "print" except for the
  // last line which is "println". This puts everything on the
  // same line, then sends a final carriage return to move to
  // the next line.

  // After you upload the sketch, turn on the serial monitor
  // (the magnifying-glass icon to the right of the icon bar).
  // You'll be able to see the sensor values. Bend the flex sensor
  // and note its minimum and maximum values. If you replace the
  // 600 and 900 in the map() function above, you'll exactly match
  // the flex sensor's range with the servo's range.

 button1State = digitalRead(button1Pin);
  button2State = digitalRead(button2Pin);



  
while(((button1State == LOW) ))
  {
    for(position = 0; position < 180; position += 2)
  {
    servo1.write(position);  // Move to next position
    delay(20);               // Short pause to allow it to move
  }
  }
  // if button1 or button 2 are pressed (but not both)
  

while ((button2State == LOW))
  {
     for(position = 180; position >= 0; position -= 1)
  {                                
    servo1.write(position--);  // Move to next position
    delay(20);               // Short pause to allow it to move
  }
  }



  
  if(flexposition >700 && flexposition < 800){
    digitalWrite(ledPin1, HIGH); 
  }else{
    digitalWrite(ledPin1, LOW); 
    }
  if(flexposition >800 && flexposition < 900){
    digitalWrite(ledPin2, HIGH); 
  }else{
    digitalWrite(ledPin2, LOW); 
    }
  if(flexposition >900 && flexposition < 1000){
    digitalWrite(ledPin3, HIGH); 
  }else{
    digitalWrite(ledPin3, LOW); 
    }
  }
  
 
