#include <Servo.h>
int A_1A = 6, A_1B = 11, B_1A = 3, B_1B = 5; //PWM -> Analog출력을 위해서
int trig = 8, echo = 9;
int servoPin = 10;
Servo servo;
int motorASpeed = 150, motorBSpeed = 150; //모터 속도를 (같게...?)조절하기 위해서, 0~255

void setup() {
  Serial.begin(9600);
  pinMode(A_1A, OUTPUT); pinMode(A_1B, OUTPUT);
  pinMode(B_1A, OUTPUT); pinMode(B_1B, OUTPUT);
  digitalWrite(A_1A, LOW); digitalWrite(A_1B, LOW); //초기화
  digitalWrite(B_1A, LOW); digitalWrite(B_1B, LOW); //초기화 안해도 될수도...?
  pinMode(trig,OUTPUT); pinMode(echo,INPUT);
  servo.attach(servoPin); servo.write(90);
}

void loop() {
  int cm = getStableDistanceCM();
  long leftDistance = 0, rightDistance = 0;
  if(cm < 25) {
    stop();  delay(500);
    servo.write(150);  delay(500);  //왼쪽
    leftDistance = getStableDistanceCM(); delay(500);
    servo.write(30);   delay(500);  //오른쪽
    rightDistance = getStableDistanceCM(); delay(500);
    servo.write(90);   delay(1000);
    back();  delay(300);
    if(leftDistance > rightDistance) left();
    else right();
    delay(500);
  } else forward();                     
}

float getDistanceCM() {
  digitalWrite(echo, LOW);
  digitalWrite(trig, LOW);
  delayMicroseconds(2);
  digitalWrite(trig,HIGH);
  delayMicroseconds(10);
  digitalWrite(trig,LOW);
  unsigned long duration=pulseIn(echo,HIGH);  //자료형을 무조건 unsigned long으로 설정해야함
  float distance=340*duration/10000.0/2.0;
  return distance;
}
float getStableDistanceCM() {
  int cmSum = 0;
  for(int i=0; i<10; i++) 
    cmSum += getDistanceCM();
  return cmSum/10;
}

void forward() {
  analogWrite(A_1A, motorASpeed);
  analogWrite(A_1B, 0);
  analogWrite(B_1A, motorBSpeed);
  analogWrite(B_1B, 0);
}

void back() {
  analogWrite(A_1A, 0);
  analogWrite(A_1B, motorASpeed);
  analogWrite(B_1A, 0);
  analogWrite(B_1B, motorBSpeed);
}

void left() {
  analogWrite(A_1A, motorASpeed);
  analogWrite(A_1B, 0);
  analogWrite(B_1A, 0);
  analogWrite(B_1B, 0);
}

void right() {
  analogWrite(A_1A, 0);
  analogWrite(A_1B, 0);
  analogWrite(B_1A, motorBSpeed);
  analogWrite(B_1B, 0);
}

void stop() {
  analogWrite(A_1A, 0);
  analogWrite(A_1B, 0);
  analogWrite(B_1A, 0);
  analogWrite(B_1B, 0);
}


