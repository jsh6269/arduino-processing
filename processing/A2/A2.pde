float y=100;
float v=0;
float a=0.1;
int r=50;
void setup(){
  size(200,400);
//  background(255);
}
void draw(){
  background(255);
  if(y>height-r/2){
    v=(-v)*0.95;
    if(abs(v)<0.2)
      v=a=0;
  }
//  if(y>height+-r)
//    v=a=0;
  v+=a;
  y+=v;
  fill(0);
  ellipse(100,y,r,r);
}
