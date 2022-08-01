#define red 2
#define yellow 3
#define green 4

void setup()
{
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);
}

void loop()
{
  digitalWrite(red, HIGH);
  delay(9000); // Wait for 1000 millisecond(s)
  digitalWrite(red, LOW);
  delay(100); // Wait for 1000 millisecond(s)
  digitalWrite(yellow,HIGH);
  delay(2000);
  digitalWrite(yellow,LOW);
  delay(100);
  digitalWrite(green,HIGH);
  delay(6000);
  digitalWrite(green,LOW);
  delay(100);
}
