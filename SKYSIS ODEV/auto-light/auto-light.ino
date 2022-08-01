#define light 8
int analogValue;

void setup()
{
  Serial.begin(9600);
  pinMode(light,OUTPUT);
}

void loop()
{
  analogValue = analogRead(A0);
  Serial.println(analogValue);
  if(analogValue < 1022)
  {
    digitalWrite(light,HIGH);
  }else
  {
    digitalWrite(light,LOW);
  }
}
