#include <Servo.h>
Servo myservo;
void setup() {
  myservo.attach(3);
  pinMode(A0,INPUT);  //가변저항
  Serial.begin(9600);
}
void loop() {
  int valueR=analogRead(A0);
  int value=map(valueR,0,1023,0,180);
  myservo.write(value);
}

