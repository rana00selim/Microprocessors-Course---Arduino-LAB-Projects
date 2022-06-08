
const int SENSOR_PIN = 0;      // Analog input pin

const int buzzerPin = 9;

const int songLength = 18;

const int buttonPin1 = 1;
const int buttonPin2 = 2;
int buttonState1 = 0;
int buttonState2 = 0;

char notes[] = "cdfda ag cdfdg gf "; // a space represents a rest

int beats[] = {1,1,1,1,1,1,4,4,2,1,1,1,1,1,1,4,4,2};

int beats2[] = {2,3,4,1,2,3,4,1,1,1,3,4,1,1,3,4,1,1};

int tempo = 113;

void setup()
{
  pinMode(buzzerPin, OUTPUT);
  pinMode(buttonPin1, INPUT);
  pinMode(buttonPin2, INPUT);
  Serial.begin(9600);
}


void loop()
{
  int sensorValue;

  sensorValue = analogRead(SENSOR_PIN);

  sensorValue = map(sensorValue, 0, 1023, 100,500);
  sensorValue = constrain(sensorValue, 100,500);

  int tempo = sensorValue;

  Serial.println(sensorValue);

  buttonState1 = digitalRead(buttonPin1);
  buttonState2 = digitalRead(buttonPin2);

  if (buttonState1 == HIGH){//***********************song1********************************
    
    int i, duration;
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
  
}//***********************song1********************************

  if (buttonState2 == HIGH){//***********************song2********************************

  int i, duration;
  for (i = 0; i < songLength; i++) // step through the song arrays
  {
    duration = beats2[i] * tempo;  // length of note/rest in ms

    if (notes[i] == ' ')          // is this a rest? 
    {
      delay(duration);            // then pause for a moment
    }
    else                          // otherwise, play the note
    {
      tone(buzzerPin, frequency2(notes[i]), duration);
      delay(duration);            // wait for tone to finish
    }
    delay(tempo/10);              // brief pause between notes
  }
}//***********************song2********************************
  
}



//---------------------------------------------------------------

int frequency(char note) 
{

  int i;
  const int numNotes = 8;  

  char names[] = { 'a', 'a', 'b', 'c', 'c', 'c', 'd', 'a' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};

  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);
    
  }

int frequency2(char note) 
{

  int i;
  const int numNotes = 8;  

  char names[] = { 'c', 'd', 'e', 'f', 'g', 'a', 'b', 'C' };
  int frequencies[] = {262, 294, 330, 349, 392, 440, 494, 523};
  
  for (i = 0; i < numNotes; i++)  // Step through the notes
  {
    if (names[i] == note)         // Is this the one?
    {
      return(frequencies[i]);     // Yes! Return the frequency
    }
  }
  return(0);
    
  }
