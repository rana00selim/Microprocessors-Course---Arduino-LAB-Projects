int datapin = 2; 
int clockpin = 3;
int latchpin = 4;
byte data = 0;
int num =0;
int count =0;

void setup()
{

  pinMode(datapin, OUTPUT);
  pinMode(clockpin, OUTPUT);  
  pinMode(latchpin, OUTPUT);
  
  Serial.begin(9600);
}


void loop()
{
  binaryCount();        // Bit patterns from 0 to 255
}


void shiftWrite(int desiredPin, boolean desiredState)

// This function lets you make the shift register outputs
// HIGH or LOW in exactly the same way that you use digitalWrite().

// Like digitalWrite(), this function takes two parameters:

//    "desiredPin" is the shift register output pin
//    you want to affect (0-7)

//    "desiredState" is whether you want that output
//    to be HIGH or LOW

// Inside the Arduino, numbers are stored as arrays of "bits",
// each of which is a single 1 or 0 value. Because a "byte" type
// is also eight bits, we'll use a byte (which we named "data"
// at the top of this sketch) to send data to the shift register.
// If a bit in the byte is "1", the output will be HIGH. If the bit
// is "0", the output will be LOW.

// To turn the individual bits in "data" on and off, we'll use
// a new Arduino commands called bitWrite(), which can make
// individual bits in a number 1 or 0.
{
  // First we'll alter the global variable "data", changing the
  // desired bit to 1 or 0:

  bitWrite(data,desiredPin,desiredState);

  // Now we'll actually send that data to the shift register.
  // The shiftOut() function does all the hard work of
  // manipulating the data and clock pins to move the data
  // into the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, data);

  // Once the data is in the shift register, we still need to
  // make it appear at the outputs. We'll toggle the state of
  // the latchPin, which will signal the shift register to "latch"
  // the data to the outputs. (Latch activates on the low-to
  // -high transition).

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);
}

void binaryCount()
{
  int ans;
    Serial.println("Type an integer (0-255): ");
  Serial.println("then click [send] or press [return]");
  Serial.println();  // Print a blank line

    while(true)  // "true" is always true, so this will loop forever.
  {
    
ans = Serial.parseInt();

    while (count = 0)
    {
num = ans; 
int bits[8] = {};

for (int i = 8; i > 0; i--) {
    bits[i] = num%2;
    num=num/2;

}
Serial.print("Num in Dec = "); 
Serial.print(ans); 
Serial.print(" is "); 
for(int i = 1; i<9; i++){
Serial.print( bits[i]);
}
Serial.println(" in Binary");


  
delay(2000);
count=1;

    }
      int delayTime = 1000; // time (milliseconds) to pause between LEDs
                        // make this smaller for faster switching

  // Send the data byte to the shift register:

  shiftOut(datapin, clockpin, MSBFIRST, ans);

  // Toggle the latch pin to make the data appear at the outputs:

  digitalWrite(latchpin, HIGH);
  digitalWrite(latchpin, LOW);

  // Delay so you can see what's going on:

  delay(delayTime);
  }
}
