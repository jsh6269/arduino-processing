int led = 9, sw = 4;
int led_state = 0, sw_state = 0;  //sw 상태 변수 추가
void setup() {
  pinMode(sw, INPUT_PULLUP);
  pinMode(led, OUTPUT);
}
void loop() {
  if(digitalRead(sw) == LOW) {  //스위치 누르면
    //스위치 상태가 누르지 않은 상태일 때만 스위치와 LED의 상태 반전 – 스위치 누르는 동안 1번만 상태 반전
    if(sw_state == 0) { 
      sw_state = 1;
      led_state = !led_state;
    }
  } else sw_state = 0;  //스위치 누르지 않으면 스위치 상태 반전
  digitalWrite(led, led_state);
}
