Ball[] myBall=new Ball[1];
class Ball{
  float x,y,r=50;
  Ball(float xi, float yi){
    x=xi;
    y=yi;
  }
  void display(){
    if(r>1) r-=0.8;
    else r=0;
    fill(random(0,255),random(0,255),random(0,255));
    circle(x,y,r);
  }
}
void setup(){
  size(640,360);
  myBall[0]=new Ball(900,900);
}
void draw(){
  background(255);
  Ball X=new Ball(mouseX,mouseY);
  myBall=(Ball[])append(myBall,X);
  for(int i=0;i<myBall.length;i++)
    myBall[i].display();
}
