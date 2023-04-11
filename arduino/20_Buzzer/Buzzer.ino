int b=10;
int melody[]={262,294,330,349,392,440,494,523};
//0:도,1:레 2:미,3:파,4:솔,5:라,6:시,7:도
void setup() {
  pinMode(b,OUTPUT);
  for(int i=0;i<8;i++){
    tone(b,melody[i]); delay(1000);
    noTone(b);
  }/* 학교교가 일부
  tone(b,melody[4]);delay(1000/4);
  tone(b,melody[7]);delay(1000/4);noTone(b); delay(30);
  tone(b,melody[7]);delay(2000/4);
  tone(b,melody[5]);delay(750/4);
  tone(b,melody[4]);delay(250/4);
  tone(b,melody[2]);delay(1000/4);noTone(b); delay(30);
  tone(b,melody[2]);delay(2000/4);
      
  tone(b,melody[0]);delay(750/4);
  tone(b,melody[2]);delay(250/4);
  tone(b,melody[4]);delay(2000/4);
  tone(b,melody[5]);delay(750/4);
  tone(b,melody[7]);delay(250/4);
  tone(b,melody[4]);delay(3000/4);

  tone(b,melody[2]*2);delay(3000);
  tone(b,melody[1]*2);delay(3000/4);
  tone(b,melody[2]*2);delay(3000/4);
  tone(b,melody[1]*2);delay(3000/4);
  
  tone(b,melody[4]);delay(3000/4);
  tone(b,melody[4]);delay(3000/4);
  tone(b,melody[4]);delay(3000/4);
  tone(b,melody[4]);delay(3000/4);
  */
}

void loop() {
  //사용하지 않아도 선언하지 않으면 에러 생김
}
