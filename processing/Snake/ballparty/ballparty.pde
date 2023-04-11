Ball[] myBall=new Ball[1];
int count=0;
int i=0,check=0;
class Ball{
  float x,y;
  float speed;
  int hang;
  float radius=random(12,20);
  float acceleration=0.1;
  float color1=random(0,255),color2=random(0,255),color3=random(0,255);
  Ball(float tempX,float tempY,float tempSpeed,int temphang){
    x=tempX;
    y=tempY;
    speed=tempSpeed;
    hang=temphang;
  }
  void move(){
    speed+=acceleration;
    y+=speed;
  }
  void bounce(){
    if(y>height-radius&&speed>0)
      speed=(-speed)*0.95;
    if(y>height-radius&&abs(speed)<0.2){
      acceleration=speed=0;
      y=999;
    }
  }
  void delete(){
    acceleration=speed=0;
    y=999;
  }
  void display(){
    stroke(0);
    if(hang==0)
      fill(color1,color2,color3);
    else
      fill(random(0,255),random(0,255),random(0,255));
    ellipse(x,y,radius*2,radius*2);
  }
}
void mousePressed(){
  Ball aBall=new Ball(mouseX,mouseY,0,0);
  myBall=(Ball[])append(myBall,aBall);
  long cnt=myBall.length;
  if(cnt%300==0&&cnt!=0){
    for(int i=0;i<myBall.length;i++)
      myBall[i].delete();
  for(int i=0;i<503;i++)
  {
    Ball bBall=new Ball(random(0,640),random(0,180),0,1);
    myBall=(Ball[])append(myBall,bBall);
  }
  }
}
void setup(){
  size(640,360);
  background(70);
  myBall[0]=new Ball(700,100,0,0);
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
    myBall[i].bounce();
    myBall[i].display();
  }
}
