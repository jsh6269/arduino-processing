int pot=A0;
int value=0;
void setup() {
  //pinMode(pot,INPUT);  //없어도 됨
  Serial.begin(9600);
}
void loop() {
  value=analogRead(pot);
  //    => 0에서 1023까지
  Serial.println(value);
  delay(10);
}
