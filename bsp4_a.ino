const byte resistorReadPin = A0;
// 10 kOhm resitor
const int resistor = 10000;

void setup()
{
  Serial.begin(9600);
  
  pinMode(resistorReadPin, INPUT);
}

void loop()
{
  float voltage = (float)analogRead(resistorReadPin)/1023*5;
  // R2 = Ua * R1 / (Uges - Ua)
  float resistorValue = voltage * resistor / (5 - voltage);
  Serial.print(resistorValue);
  Serial.println(" Ohm");
  delay(1000);
}