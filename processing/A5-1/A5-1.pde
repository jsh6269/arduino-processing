float theta=0;
float r=10;
float cnt=1;
void setup(){
  size(640,360);
  background(255);
}
void draw(){
  float x=r*cos(theta);
  float y=r*sin(theta);
  float centerx=320;
  float centery=180;
  fill(0);
  ellipse(centerx+x,centery+y,10,10);
  theta+=0.01;
  r+=0.1;
}
