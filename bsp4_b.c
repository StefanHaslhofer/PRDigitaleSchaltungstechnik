const byte capacitorReadPin = A0;
const byte powerPin = 10;
long tau;

// counter to check how long the condensator takes to load
unsigned long timer;
// 10 kOhm resitor
const int resistor = 10000;

void setup()
{
  Serial.begin(9600);
  
  timer = millis();
  pinMode(capacitorReadPin, INPUT);
  pinMode(powerPin, OUTPUT);
}

void loop()
{
  digitalWrite(powerPin, HIGH);
  
  timer = millis();
  // load the capacitor to 63% capacity
  while ((float)analogRead(capacitorReadPin)/1023 < 0.63);
  
  // 1tau is reached if capacitor is 63% charged
  tau = millis() - timer;
  
  // tau = R * C -> c = tau/R (tau in milliseconds -> /1000 ti get SI)
  float capacity = (float)tau/resistor/1000;
  
  // 10^6 because we want to visualize mikrofarad
  Serial.print(capacity*1000000);
  Serial.println(" Mikrofarad");
  
  digitalWrite(powerPin, LOW);
  
  // unload the capacitor
  while((float)analogRead(capacitorReadPin) > 0);
}