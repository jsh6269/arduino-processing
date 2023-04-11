Ball[] myBall=new Ball[1];
class Ball{
  float x,y,r,check;
  Ball(float xi, float yi, float ri,int checki){
    x=xi;
    y=yi;
    r=ri;
    check=checki;
  }
  void display(){
    r-=0.8;
    if(check==1)
      r+=0.4;
    if(r<0)
      r=0;
   if(check==0)
    stroke(random(0,255),random(0,255),random(0,255));
   else{
    stroke(54,138,255);
    y+=0.45;
   }
    fill(0);
    circle(x,y,r*0.45);
    drawflakes(x,y,r);
  }
  void snowflakes(){
    float l=r/3;
    if(l>0.00001){
    drawflakes(x+r*0.5,y,l);
    drawflakes(x-r*0.5,y,l);
    drawflakes(x-r*0.5/2,y-r*0.5*sqrt(3)/2,l);
    drawflakes(x+r*0.5/2,y-r*0.5*sqrt(3)/2,l);
    drawflakes(x-r*0.5/2,y+r*0.5*sqrt(3)/2,l);
    drawflakes(x+r*0.5/2,y+r*0.5*sqrt(3)/2,l);
    }
  }
}
void drawflakes(float x, float y, float l){
  if(l>0.00001){
  line(x,y-l/2,x,y+l/2);
  line(x-sqrt(3)*l/4,y+l/4,x+sqrt(3)*l/4,y-l/4);
  line(x-sqrt(3)*l/4,y-l/4,x+sqrt(3)*l/4,y+l/4);
  }
}
void make_Ball(){
  Ball aBall=new Ball(mouseX,mouseY,45,0);
  myBall=(Ball[])append(myBall,aBall);
  if(myBall.length%30==0){
    Ball bBall=new Ball(random(0,640),random(0,360),55,1);
    myBall=(Ball[])append(myBall,bBall);
  }
}
void setup(){
  size(640,360);
  background(0);
  myBall[0]=new Ball(900,900,0,0);
}
void draw(){
  background(0);
  make_Ball();
  for(int i=0;i<myBall.length;i++){
    myBall[i].display();
    myBall[i].snowflakes();
  }
}
