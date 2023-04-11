//가변저항을 돌리는 정도에 따라 LED깜빡임 주기가 그라데이션
int sensorPin = A0;
int ledPin = 13;   
int sensorValue = 0;
void setup() {
  pinMode(ledPin, OUTPUT);
}
void loop() {
  sensorValue = analogRead(sensorPin);
  digitalWrite(ledPin, HIGH);
  delay(sensorValue);
  digitalWrite(ledPin, LOW);
  delay(sensorValue);
}
