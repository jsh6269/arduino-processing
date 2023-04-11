int LED=2;
int SW=12;
void setup() {
  pinMode(LED,OUTPUT);
  pinMode(SW,INPUT_PULLUP); //보드의 내부저항 이용
}
void loop() {
 if(digitalRead(SW)==LOW) //스위치 열림
    digitalWrite(LED,HIGH);
 else                     //스위치 닫힘
    digitalWrite(LED,LOW);
}
