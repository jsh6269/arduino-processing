void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
}
void loop() {
  digitalWrite(LED_BUILTIN,HIGH); //내장 LED켜짐
  delay(1000); //1000ms=1s기다림
  digitalWrite(LED_BUILTIN,LOW); //꺼짐
  delay(1000); //1s기다림
}
