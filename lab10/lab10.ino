
#include <LiquidCrystal.h>


LiquidCrystal lcd(12,11,5,4,3,2);
const int buttonPin = 6; 
int buttonState = 0;

int lightLevel, high = 0, low = 1023;

void setup()
{
  pinMode(buttonPin, INPUT);
  lcd.begin(16, 2);
  lcd.clear();
}

void loop()
{
  lcd.setCursor(0,1);
  int sensorValue = analogRead(A1);
  buttonState = digitalRead(buttonPin);


if (buttonState == HIGH) {
     lcd.clear();
  } else {
    if(sensorValue > 980){
      lcd.print("Dark  => ");
    }else{
      lcd.print("Light  => ");
      }
    lcd.print(sensorValue);
    
    
  }



  // TIP: Since the numeric data we're sending is always growing
  // in length, new values will always overwrite the previous ones.
  // However, if you want to display varying or decreasing numbers
  // like a countdown, you'll find that the display will leave
  // "orphan" characters when the new value is shorter than the
  // old one.

  // To prevent this, you'll need to erase the old number before
  // writing the new one. You can do this by overwriting the
  // last number with spaces. If you erase the old number and
  // immediately write the new one, the momentary erase won't 
  // be noticeable. Here's a typical sequence of code:

  // lcd.setCursor(0,1);   // Set the cursor to the position
  // lcd.print("       "); // Erase the largest possible number
  // lcd.setCursor(0,1);   // Reset the cursor to the original position
  // lcd.print(millis()/1000); // Print our value

}
