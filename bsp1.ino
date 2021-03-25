// set output pins
const byte redPin = 11;
const byte yellowPin = 10;
const byte greenPin = 9;

void setup()
{
  // all are output pins
  pinMode(redPin, OUTPUT);
  pinMode(yellowPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
}

void loop()
{
  // phase 1: 4 second red
  digitalWrite(redPin,1);
  delay(4000);
  
  // phase 2: turn on yellow light
  digitalWrite(yellowPin,1);
  delay(1000);
  digitalWrite(redPin,0);
  digitalWrite(yellowPin,0);
  
  // phase 3: 4s red + 4 blinks
  digitalWrite(greenPin,1);
  delay(4000);
  digitalWrite(greenPin,0);
  
  for (int i = 0; i < 4; i++) {
    delay(500);
   	digitalWrite(greenPin,1);
  	delay(500);
  	digitalWrite(greenPin,0);
  }
  
  // phase 4: 1s yellow
  digitalWrite(yellowPin,1);
  delay(1000);
  digitalWrite(yellowPin,0);
}