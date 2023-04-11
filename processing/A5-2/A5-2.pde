float start=100;
float end=1180;
void setup(){
  size(1280,360);
  background(255);
}
void draw(){
  drawcircle(640,180,160);
}
void drawcircle(float x, float y, float r){
  if(r<0.1)
    return;
  circle(x,y,r*2);
  drawcircle((start+x)/2,y,r/2);
  drawcircle((x+end)/2,y,r/2);
}
