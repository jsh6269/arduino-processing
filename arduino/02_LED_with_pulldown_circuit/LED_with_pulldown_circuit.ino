int LED=2;
int SW=12;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(SW,INPUT);
}
void loop() { //풀다운 저항으로 회로를 구성함
 if(digitalRead(SW)==HIGH) //스위치 열림
    digitalWrite(LED,HIGH);
 else                     //스위치 닫힘
    digitalWrite(LED,LOW);
}
