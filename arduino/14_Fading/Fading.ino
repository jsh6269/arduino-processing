int ledPin = 9;
void setup() {
  //쓸 내용이 없어도 함수는 만들어야 에러가 안남
}
void loop() {
  for (int fadeValue = 0 ; fadeValue <= 255; fadeValue += 5) {
    analogWrite(ledPin, fadeValue);
    delay(30); 
    //어느 정도 시간간격이 있어야 눈으로 fading effect를 보기 쉬움
  }
  for (int fadeValue = 255 ; fadeValue >= 0; fadeValue -= 5) {
    analogWrite(ledPin, fadeValue);
    delay(30);
  }
}


