const byte redLeft = 9;
const byte yellowLeft = 10;
const byte green = 11;
const byte yellowRight = 12;
const byte redRight = 13;

const byte buttonPin = 2;
const byte greenIn = 5;

// # button was correctly pressed
volatile int pressedCount = 1;

volatile byte greenState = LOW;
volatile byte restart = 0;

volatile byte greenPressed = 0;


void setup()
{
  pinMode(redLeft, OUTPUT);
  pinMode(yellowLeft, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(yellowRight, OUTPUT);
  pinMode(redRight, OUTPUT);
  
  pinMode(buttonPin, INPUT);
  pinMode(greenIn, INPUT);
  
  // increase speed when button is pressed
  attachInterrupt(digitalPinToInterrupt(buttonPin), increaseSpeed, FALLING);
}

void loop()
{
  // loop over all pins
  for(int i = redLeft; i < redRight + 1; i++) {
      
    // end loop on game end
    if (restart == 1) {
      i = redRight + 1;
      
      // flash all lights on game end
      for(int k = 0; k < 3; k++) {
        for(int j = redLeft; j < redRight + 1; j++) {
          digitalWrite(j, HIGH); 
        }
        delay(500);
        for(int j = redLeft; j < redRight + 1; j++) {
          pressedCount = 1;
          digitalWrite(j, LOW); 
        }
        delay(500);
      }
      
      restart = 0;
    } else {
      digitalWrite(i, HIGH); 
      delay(5000/pressedCount);
      
      // restart game if player missed green light
      if (i == green && greenPressed < 1) {
        restart = 1;
      }
      greenPressed = 0;
      
      digitalWrite(i, LOW);
    }
  }
}

void increaseSpeed()
{
  greenState = digitalRead(greenIn);
  
  if(greenState == HIGH) {
  	pressedCount++;
    digitalWrite(green, LOW);
    greenPressed = 1;
  } else {
   	pressedCount = 1; 
    // restart the game
    restart = 1;
  }
}