boolean cnt[5];   // 0: 처음누름 1: 누르고 있는 중 
boolean state[5]; // 0:꺼짐, 1:켜짐
void setup() {
  for(int i=2;i<=4;i++)
    pinMode(i,INPUT_PULLUP);//스위치 digital2,3,4
  for(int i=5;i<=7;i++)
    pinMode(i,OUTPUT);//5:red,6:green,7:yellow
}
void loop() { 
  for(int i=2;i<=4;i++){
   if(digitalRead(i)==LOW){
      if(cnt[i]==false){   //처음 누른경우 false
        cnt[i]=true;       //누르고 있는 중에는 true
        state[i]=!state[i];
        digitalWrite(i+3,state[i]);
       }
     }else cnt[i]=false;   //스위치가 눌리지 않은 경우 false
   }
}
