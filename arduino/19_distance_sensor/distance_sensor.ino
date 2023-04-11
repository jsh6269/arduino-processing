int Trig = 12; int Echo = 13; int buzzer = 8;
void setup() {
  Serial.begin(9600);
  pinMode(Trig, OUTPUT);
  pinMode(Echo, INPUT);
}
void loop() {
  digitalWrite(Trig, LOW);  //이하 3줄은 초기화
  digitalWrite(Echo, LOW);
  delayMicroseconds(2);
  digitalWrite(Trig, HIGH); //초음파 보내기
  delayMicroseconds(10);  //10마이크로초동안...
  digitalWrite(Trig, LOW);  //초음파 끊기
  unsigned long duration = pulseIn(Echo, HIGH); 
  float distance = ((float)(340*duration)/10000) / 2;
  if(distance < 5){
    tone(buzzer, 1000, 100);  delay(100);
  }
  Serial.print(distance);
  Serial.println("cm");
}
