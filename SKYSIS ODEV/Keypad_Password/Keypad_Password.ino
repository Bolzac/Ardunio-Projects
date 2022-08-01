#include <Keypad.h>

#define red 3
#define green 12
#define blue 13

const byte rows = 4;
const byte columns = 4;
char keys[rows][columns] = {
  {'1','2','3','A'},
  {'4','5','6','B'},
  {'7','8','9','C'},
  {'*','0','#','D'}
};

byte rowPins[rows] = {4,5,6,7};
byte columnpins[columns] = {11,10,9,8};

Keypad keypad(makeKeymap(keys), rowPins, columnpins, rows, columns );
String password = "";
String tempPass = "";
bool isTherePass = false;
bool passwordAssignMode = false;
bool passwordEnterMode = false;
int counter = 0;
int counterForEnter = 0;
bool a = true;


void setup()
{
  Serial.begin(9600);
  pinMode(red,OUTPUT);
  pinMode(blue,OUTPUT);
  pinMode(green,OUTPUT);
  Serial.begin(9600);
}

void loop()
{
  char key = keypad.getKey();
  if(key)
  {
    if(key == 'A' && counter != 5)
    {
        passwordAssignMode = true;  
    }
    if(passwordAssignMode)
        {
            Serial.println("Password Assigning");
          digitalWrite(blue,HIGH);
          if(counter == 1)
          {
             password = password+key;
          }
          if(counter == 2)
          {
             password = password+key;
          }
          if(counter == 3)
          {
            password = password+key;
          }
            if(counter == 4)
            {
            password = password+key;
            passwordAssignMode = false;
            digitalWrite(blue,LOW);
            }
          counter++;
      }
    if(key == 'B' && counter == 5)
    {
      passwordEnterMode = true;
    }
    if(passwordEnterMode)
    {
      Serial.println("Password entering");
        digitalWrite(blue,HIGH);
        if(counterForEnter == 1)
        {
          tempPass = tempPass+key;
        }
        if(counterForEnter == 2)
        {
          tempPass = tempPass+key;
        }
        if(counterForEnter == 3)
        {
          tempPass = tempPass+key;
        }
        if(counterForEnter == 4)
        {
          tempPass = tempPass+key;
          passwordEnterMode = false;
          digitalWrite(blue,LOW);
        }
        counterForEnter++;
    }
    if(counterForEnter == 5)
    {
      if(password == tempPass)
        {
          digitalWrite(green,HIGH);
            delay(5000);
            digitalWrite(green,LOW);
        }else
        {
            tempPass = "";
            counterForEnter = 0;
          digitalWrite(red,HIGH);
            delay(5000);
            digitalWrite(red,LOW);
        }
    }
    if(key == 'C')
    {
      password = "";
        counter = 0;
    }
  }
}
