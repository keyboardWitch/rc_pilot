#include <Arduino.h>
#include <ESP32Servo.h>

Servo upperarm_servo;        
Servo forearm_servo;        

int sigPin=1;
int sigVal;

void setup() {
  Serial.begin(115200);
  upperarm_servo.attach(2);
  forearm_servo.attach(3);
  pinMode(sigPin,INPUT); //配置引脚1为输入

}
void action(){

  upperarm_servo.write(120);
  delay(400);
  for (int j=0;j<3;j++){
    for (int i=45; i<130; i+=2) {
        forearm_servo.write(i);
        delay(5);
    }
    delay(200);
    for (int i=130; i>45; i-=2) {
        forearm_servo.write(i);
        delay(5);
    }
    delay(200);
  }
  forearm_servo.write(45);
  delay(600);
  upperarm_servo.write(50);
  delay(600);
}

void loop() {
      delay(2000);
      // Serial.print();
      sigVal = pulseIn(sigPin,HIGH);
      if (sigVal <1200){
        action();
      }
      // action();

}
