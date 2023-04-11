float x=random(60,740);
float y=random(60,540);
float vx=1,vy=2;
float temp1=150,temp2=150,temp3=150;
int r=50;
float temp=255;
void setup(){
  size(800,600);
  background(255);
}
void draw(){
  background(temp1,temp2,temp3);
  if(x>800-r||x<r){
    vx=-vx;
    temp1=random(150,255);
    temp2=random(150,255);
    temp3=random(150,255);
  }
  if(y<r||y>600-r){
    vy=-vy;    
    temp1=random(10,245);
    temp2=random(10,245);
    temp3=random(10,245);
  }
  y+=vy;
  x+=vx;
  fill(0);
  circle(x,y,r);
  stroke(0);
}
