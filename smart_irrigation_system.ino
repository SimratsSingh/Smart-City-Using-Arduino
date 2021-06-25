#include <DHT.h>
#define dht_apin A0 // Analog Pin sensor is connected to
#include<Servo.h>
Servo servo;
int angle = 0;
void setup() {
/* 
https://create.arduino.cc/projecthub/techno_z/dht11-temperature-humidity-sensor-98b03b
 */
dht DHT;
 
void setup(){

  servo.attach(3);
  Serial.begin(9600);
  delay(500);
  Serial.println("DHT11 Humidity & temperature Sensor\n\n");
  delay(1000);
 
}
 
void loop(){
 
    DHT.read11(dht_apin);
    
    Serial.print("Current humidity = ");
    Serial.print(DHT.humidity);
    if (DHT.humidity>=80){
      servo.write(60);
      delay(1500);  
    }
    else if (DHT.humidity<80 && DHT.humidity>40){
      servo.write(120);
      delay(1500);
    }
    else if (DHT.humidity<40){
      servo.write(180);
      delay(1500);  
    } 
    delay(5000);
 
}
