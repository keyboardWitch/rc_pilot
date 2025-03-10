#include <Arduino.h>
#include <ESP32Servo.h>

Servo upperarm_servo;        
Servo forearm_servo;        
Servo waist_servo;        

int sigPin=4;
int sigVal;

void setup() {
  Serial.begin(115200);
  upperarm_servo.attach(2);
  forearm_servo.attach(3);
  waist_servo.attach(1);

  pinMode(sigPin,INPUT); //配置引脚1为输入

}
void action(){
  // 抬手
      // upperarm_servo.write(140);

  for (int j=10;j<100;j+=2){
    upperarm_servo.write(j);
    delay(15);
  }
  // 转身
  int forearm_step = 4;
  int forearm_low = 40;
  int forearm_high = 120;
  int forearm_status = 40;
  int forearm_turn = 1;

  for (int x = 80;x<160;x+=1){
    waist_servo.write(x);
    if (forearm_turn==1){//正向挥
      forearm_status += forearm_step;
    }
    else{
      forearm_status -= forearm_step;
    }
    if (forearm_status>=forearm_high){
      forearm_turn=0;
    }
    if (forearm_status<=forearm_low){
      forearm_turn=1;
    }

    forearm_servo.write(forearm_status); 
    delay(20);
  }
  for (int j=0;j<3;j++){
    for(int i=forearm_status;i<120;i+=4){
      forearm_servo.write(i);  
      delay(20);  
    }
    for(int i=120;i>40;i-=4){
      forearm_servo.write(i);  
      delay(20);  
    }
  }
  forearm_status = 40;
  
  // delay(600);
  // 转回来
    for (int x = 160;x>80;x-=1){
    waist_servo.write(x);
    if (forearm_turn==1){//正向挥
      forearm_status += forearm_step;
    }
    else{
      forearm_status -= forearm_step;
    }
    if (forearm_status>=forearm_high){
      forearm_turn=0;
    }
    if (forearm_status<=forearm_low){
      forearm_turn=1;
    }

    forearm_servo.write(forearm_status); 

    delay(20);
  }
  // 收小臂
  for(int i=forearm_status;i>40;i-=2){
    forearm_servo.write(i);
    delay(20);
  }
  // 放下手
  // upperarm_servo.write(140);

    for (int j=100;j>10;j-=2){
    upperarm_servo.write(j);
    delay(20);
  }
  delay(600);
}

void loop() {
      delay(2000);
      // Serial.print();
      // sigVal = pulseIn(sigPin,HIGH);
      // if (sigVal <1200){
      //   action();
      // }
      action();

}
