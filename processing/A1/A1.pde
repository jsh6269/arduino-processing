void setup(){
  size(640,360);
}
void draw(){
  rectMode(CORNER);
  fill(0); //black rectangle
  background(255); //white background
  if(0<=mouseX&&mouseX<=width/2&&0<=mouseY&&mouseY<=height/2) 
    rect(0,0,320,180);
  else if(0<=mouseX&&mouseX<=width/2&&height/2<mouseY&&mouseY<=height)
    rect(0,180,320,180);
  else if(width/2<mouseX&&mouseX<=width&&0<=mouseY&&mouseY<=height/2)
    rect(320,0,320,180);
  else rect(320,180,320,180);
  stroke(0);
  line(width/2,0,width/2,height);
  line(0,height/2,width,height/2);
}
