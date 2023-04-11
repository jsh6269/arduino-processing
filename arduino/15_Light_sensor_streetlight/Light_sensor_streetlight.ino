void setup() {
  pinMode(2,OUTPUT);
  pinMode(A1,INPUT);  //조도센서가 풀업방식으로 연결됨
  Serial.begin(9600);
}
void loop() {
  int value=analogRead(A1);
  Serial.println(value); 
  //어두울 때 1000 근처, 밝을 때 800~900의 값을 가짐 
    if(value>950) //어두울 때 LED를 킨다. (가로등)
      digitalWrite(2,HIGH);
    else  digitalWrite(2,LOW); //밝을 때 LED를 끈다.
}
