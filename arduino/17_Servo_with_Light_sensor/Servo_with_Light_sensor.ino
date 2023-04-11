#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(3);
  //갈색:GND,빨간색:5V,주황색:PWM
  pinMode(A1,INPUT);  //조도센서
  Serial.begin(9600);
}
void loop() {
  int valueL=analogRead(A1);
  Serial.println(valueL);
    if(valueL>950) //어두우면 0도
      myservo.write(0);
    else  //밝으면 180도
      myservo.write(180);
}

