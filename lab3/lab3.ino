/*
SparkFun Inventor's Kit 
Example sketch 05

PUSH BUTTONS

  Use pushbuttons for digital input

This sketch was written by SparkFun Electronics,
with lots of help from the Arduino community.
This code is completely free for any use.
Visit http://learn.sparkfun.com/products/2 for SIK information.
Visit http://www.arduino.cc to learn about the Arduino.

*/


// First we'll set up constants for the pin numbers.
// This will make it easier to follow the code below.

 // pushbutton pin
 const int buttonPin1 = 3;//change color
 const int buttonPin2 = 4;//change speed
 const int buttonPin3 = 5;//onoff
  
 //RGB LED pins
 const int redPin = 11;    
 const int greenPin = 10;
 const int bluePin = 9;

int stateLED = LOW;
int previous = LOW;

//create a variable to store a counter and set it to 0
int counter = 0;
void setup()
{
  // Set up the pushbutton pins to be an input:
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  pinMode(buttonPin3, INPUT);

  // Set up the RGB pins to be an outputs:
  pinMode(redPin, OUTPUT);  
  pinMode(greenPin,OUTPUT);
  pinMode(bluePin,OUTPUT);
  
}


void loop()
{
 // local variable to hold the pushbutton states
  int buttonState1;  
  int buttonState2;
  int buttonState3;

  //read the digital state of buttonPin with digitalRead() function and store the           //value in buttonState variable
  buttonState1 = digitalRead(buttonPin1);

  //if the button is pressed increment counter and wait a tiny bit to give us some          //time to release the button
  if (buttonState1 == LOW) // light the LED
  {
    counter++;
    delay(150);
  }

  //use the if satement to check the value of counter. If counter is equal to 0 all         //pins are off
  if(counter == 0)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,LOW);
   digitalWrite(bluePin,LOW);
  }

  //else if counter is equal to 1, redPin is HIGH
  else if(counter == 1)
  {
   digitalWrite(redPin,HIGH);
   digitalWrite(greenPin,LOW);
   digitalWrite(bluePin,LOW);
  }

  //else if counter is equal to 2 greenPin is HIGH
  else if(counter ==2)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,HIGH);
   digitalWrite(bluePin,LOW);
  }

  //else if counter is equal to 3 bluePin is HIGH
  else if(counter ==3)
  {
   digitalWrite(redPin,LOW);
   digitalWrite(greenPin,LOW);
   digitalWrite(bluePin,HIGH);
  }

  //else reset the counter to 0 (which turns all pins off)
  else
  {
   counter =0;
  }



  
  buttonState2 = digitalRead(buttonPin2);
  if (buttonState2 == LOW) // light the LED
  {
    mainColors();
  }


 buttonState3 = digitalRead(buttonPin3);
 if(buttonState3 == HIGH ) {
    if(stateLED == HIGH){
      stateLED = LOW; 
    } else {
       stateLED = HIGH; 
    }
   
  }
  digitalWrite(redPin, stateLED);
  digitalWrite(greenPin, stateLED);
  digitalWrite(bluePin, stateLED);
  
  
}




// Here's the mainColors() custom function we've written.
void mainColors()
{
// Off (all LEDs off):
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);

//wait 1 second
delay(1000);

// Red (turn just the red LED on):
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, LOW);

//wait 1 seconds
delay(1000);

// Green (turn just the green LED on):
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, LOW);

//wait 1 second
delay(1000);

// Blue (turn just the blue LED on):
digitalWrite(redPin, LOW);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);

//wait 1 second
delay(1000);

// Yellow (turn red and green on):
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, LOW);

//wait 1 second
delay(1000);

// Cyan (turn green and blue on):
digitalWrite(redPin, LOW);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, HIGH);

//wait 1 second
delay(1000);

// Purple (turn red and blue on):
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, LOW);
digitalWrite(bluePin, HIGH);

//wait 1 second
delay(1000);

// White (turn all the LEDs on):
digitalWrite(redPin, HIGH);
digitalWrite(greenPin, HIGH);
digitalWrite(bluePin, HIGH);

//wait 1 second
delay(1000);
}
