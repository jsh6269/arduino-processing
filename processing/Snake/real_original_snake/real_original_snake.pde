float xpos[]=new float[80];
float ypos[]=new float[80];
float range[]=new float[80];
void setup(){
  size(640,360);
  
}
void draw(){
  background(255);
  for(int i=0;i<=78;i++)
  {
    xpos[i]=xpos[i+1];
    ypos[i]=ypos[i+1];
    if(range[i+1]>0.8)
      range[i]=range[i+1]-0.8;
    else range[i]=0;
  }
  xpos[79]=mouseX;
  ypos[79]=mouseY;
  range[79]=50;
  for(int i=0;i<80;i++)
    circle(xpos[i],ypos[i],range[i]);
}
