#define mp1 6
#define mp2 5
#define mp3 9
#define mp4 10
#include <Servo.h>
Servo myservo;
char t="";
int pos = 0;  

void setup() {
  // put your setup code here, to run once:
  pinMode(6, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(11, OUTPUT);
  myservo.attach(3);
  Serial.begin(9600);
  

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available())
  {
    t=Serial.read();
    Serial.println(t);
  }
  if(t=='F')
  {
    digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10,LOW);
  }
  else if(t=='B')
  {
    digitalWrite(6, LOW);
    digitalWrite(5, HIGH);
    digitalWrite(9, LOW);
    digitalWrite(10,HIGH);
  }
  else if(t=='L')
  {    digitalWrite(9, LOW);
    digitalWrite(10, LOW);
     digitalWrite(6, HIGH);
    digitalWrite(5, LOW);
  }
else if(t=='R')
{   digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, HIGH);
    digitalWrite(10, LOW);
    }
else if(t=='S')
{ 
  digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
}
else if(t=='P')
{
  digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    myservo.write(90);
    
}
else if(t=='D')
{
  digitalWrite(6, LOW);
    digitalWrite(5, LOW);
    digitalWrite(9, LOW);
    digitalWrite(10,LOW);
    myservo.write(0);
}
}
