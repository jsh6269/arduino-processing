int state[4];
void setup() {
  Serial.begin(9600);
  for(int i=5;i<=7;i++)
    pinMode(i,OUTPUT);//5:red,6:green,7:yellow
}
void loop() { 
  while(Serial.available()){
    char code=(char)Serial.read();
    if(code=='r'||code=='R'){
      state[1]=!state[1];
      digitalWrite(5,state[1]);
    }
    else if(code=='g'||code=='G'){
      state[2]=!state[2];
      digitalWrite(6,state[2]);
    }
    else if(code=='y'||code=='Y'){
      state[3]=!state[3];
      digitalWrite(7,state[3]);
    }
    else Serial.println("Error occured");
  }
}
