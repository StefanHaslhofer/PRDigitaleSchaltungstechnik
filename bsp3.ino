// A and B output pins
const byte pinA = 9;
const byte pinB = 10;

// result Input pins
const byte resultPin = 2;
char gate[] = "";

void setup()
{
  Serial.begin(9600);
  
  pinMode(pinA, OUTPUT);
  pinMode(pinB, OUTPUT);

  pinMode(resultPin, INPUT);
}

void loop()
{
  // boolean for gate results
  // z = zero; o = one
  bool zzResult = 0;
  bool zoResult = 0;
  bool ozResult = 0;
  bool ooResult = 0;
  
  // A = 0, B = 0
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, LOW);
  zzResult = digitalRead(resultPin);
  
  // A = 0, B = 1
  digitalWrite(pinA, LOW);
  digitalWrite(pinB, HIGH);
  zoResult = digitalRead(resultPin);
  
  // A = 1, B = 0
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, LOW);
  ozResult = digitalRead(resultPin);
  
  // A = 1, B = 1
  digitalWrite(pinA, HIGH);
  digitalWrite(pinB, HIGH);
  ooResult = digitalRead(resultPin);
  
  checkGate(zzResult, zoResult, ozResult, ooResult);
  
  delay(5000);
}

void checkGate(bool zzResult, bool zoResult, bool ozResult, bool ooResult) {
  if(zzResult == 0 && zoResult == 0 && ozResult == 0 && ooResult == 1) {
	Serial.println("AND");
  } else if(zzResult == 0 && zoResult == 1 && ozResult == 1 && ooResult == 1) {
    Serial.println("OR");
  } else if(zzResult == 1 && zoResult == 1 && ozResult == 1 && ooResult == 0) {
     Serial.println("NAND");
  } else if(zzResult == 1 && zoResult == 0 && ozResult == 0 && ooResult == 0) {
     Serial.println("NOR");
  } else if(zzResult == 0 && zoResult == 1 && ozResult == 1 && ooResult == 0) {
     Serial.println("XOR");
  }
}