#include<Servo.h>
#define ir1 14
#define ir2 19
#define led1 10
#define led2 11
#define led3 9
#define sensor_pin 15
#define e 5
#define t 6
long duration; 
int output_value ;   
long distance;
Servo servo;
int angle = 90;

void IR1()
{
  digitalWrite(led1, HIGH);
  Serial.println("ir1 woeking");



}
void IR2()
{
  digitalWrite(led2, HIGH);
  Serial.println("ir2 woeking");

}
void setup()


{Serial.begin(9600);
  servo.attach(3);
  pinMode(ir1, INPUT);
  pinMode(ir2, INPUT);
  pinMode(led1, OUTPUT);
  pinMode(led2, OUTPUT);
  pinMode(led3, OUTPUT);
    pinMode(e, INPUT);
  pinMode(t, OUTPUT);
}
void loop(){
  Serial.println("hey");
 if (digitalRead(ir1)){
    IR1();
    }
 else{
  digitalWrite(led1,LOW);
 }
  if (digitalRead(ir2)){
    IR2();
    }
   else{
  digitalWrite(led2,LOW);
 }
  digitalWrite(t, LOW);
  delayMicroseconds(2);
 
  digitalWrite(t, HIGH);
  delayMicroseconds(3);

   digitalWrite(t, LOW);
   duration = pulseIn(e, HIGH);

   distance=duration/58.2;

   Serial.println(distance);
   if (distance < 5){
    digitalWrite(led3, HIGH);
    Serial.println("waste working");
    }
   else{
  digitalWrite(led3,LOW);
 }
    output_value= analogRead(sensor_pin);
    output_value = map(output_value,550,0,0,100);
    Serial.print("Mositure : ");
    

   Serial.print(output_value);
    Serial.println("%");
   if(output_value<30){
    servo.write(0);
    delay(1500);  
    servo.write(90);
    delay(1000);
  }
    
   

  

   delay(1000);
   

   }



  

  
