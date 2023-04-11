Ball[] myBall=new Ball[1];
int i=0,check=0;
class Ball{
  float x,y;
  float speed;
  float acceleration=0.1;
  Ball(float tempX,float tempY,float tempSpeed){
    x=tempX;
    y=tempY;
    speed=tempSpeed;
  }
  void move(){
    speed+=acceleration;
    y+=speed;
  }
  void bounce(int x){
    if(y<0+16||y>height-16&&speed>0)
      speed=(-speed)*0.95;
    if(y<16&&abs(speed)<0.2)
      acceleration=speed=0;
  }
  void display(){
    stroke(0);
    fill(random(10,255),random(10,255),random(10,255));
    ellipse(x,y,32,32);
  }
}
void mousePressed(){
  Ball aBall=new Ball(mouseX,mouseY,0);
  myBall=(Ball[])append(myBall,aBall);
}
void setup(){
  size(640,360);
  background(70);
  myBall[0]=new Ball(700,100,0);
}
void draw(){

  background(70);
  if(mousePressed==true&&check==0){
    mousePressed();
    check=1;
  }
  else if(mousePressed==false||pmouseX!=mouseX||pmouseY!=mouseY) check=0;
  for(int i=0;i<myBall.length;i++)
  {
    myBall[i].move();
    myBall[i].bounce(i);
    myBall[i].display();
  }
}
