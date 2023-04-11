byte digits[10][8]={
  {1,1,1,1,1,1,0,0},{0,1,1,0,0,0,0,0},
  {1,1,0,1,1,0,1,0},{1,1,1,1,0,0,1,0},
  {0,1,1,0,0,1,1,0},{1,0,1,1,0,1,1,0},
  {1,0,1,1,1,1,1,0},{1,1,1,0,0,1,0,0},
  {1,1,1,1,1,1,1,0},{1,1,1,1,0,1,1,0}
};
void setup() {
  Serial.begin(9600);
  for(int i=2;i<10;i++)
    pinMode(i,OUTPUT);
  pinMode(A0,INPUT);
}
void loop() {
  int value=analogRead(A0);
  value=map(value,0,1023,0,9);
  displayDigit(value);
  Serial.println(value);
}
void displayDigit(int num){
  for(int i=0;i<8;i++)
    digitalWrite(i+2,!digits[num][i]);
}

