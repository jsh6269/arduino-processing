Snake[] object=new Snake[120];
int cnt=0;
int check=0;
class Snake{
  float xpos;
  float ypos;
  float range=50;
  float a1=0,a2,a3,a4;
  float b1=random(0,255);
  float b2=random(0,255);
  float b3=random(0,255);
  Snake(){
    xpos=mouseX;
    ypos=mouseY;
  }
  void display(){
    if(range>0.8) range-=0.8;
    else range=0;
    if(key=='1'){
      fill(0,0);
      stroke(0);
    }
    else if(key=='2')
      fill(random(0,255),random(0,255),random(0,255));
    else if(key=='3')
      fill(b1,b2,b3,60);
    if(key=='r'){
      stroke(255);
      fill(255);
    }
    if(key=='s'){
      float l=range/3;
      if(range/3>0.00001){
        partytime(xpos+range*0.5,ypos,l);
        partytime(xpos-range*0.5,ypos,l);
        partytime(xpos-range*0.5/2,ypos-range*0.5*sqrt(3)/2,l);
        partytime(xpos+range*0.5/2,ypos-range*0.5*sqrt(3)/2,l);
        partytime(xpos-range*0.5/2,ypos+range*0.5*sqrt(3)/2,l);
        partytime(xpos+range*0.5/2,ypos+range*0.5*sqrt(3)/2,l);      
    }
    }
    else if(key=='d'){
      float l=range/3;
      if(range/3>0.00001){
        glitter(xpos+range*0.5,ypos,l);
        glitter(xpos-range*0.5,ypos,l);
        glitter(xpos-range*0.5/2,ypos-range*0.5*sqrt(3)/2,l);
        glitter(xpos+range*0.5/2,ypos-range*0.5*sqrt(3)/2,l);
        glitter(xpos-range*0.5/2,ypos+range*0.5*sqrt(3)/2,l);
        glitter(xpos+range*0.5/2,ypos+range*0.5*sqrt(3)/2,l);      
    }      
    }
    else if(key=='a'){
      float l=range/3;
      stroke(random(0,255),random(0,255),random(0,255));
      ypos+=0.5;
      drawflakes(xpos,ypos,range);
      fill(0,0);
      circle(xpos,ypos,range*0.45);
      if(range/3>0.00001){
        drawflakes(xpos+range*0.5,ypos,l);
        drawflakes(xpos-range*0.5,ypos,l);
        drawflakes(xpos-range*0.5/2,ypos-range*0.5*sqrt(3)/2,l);
        drawflakes(xpos+range*0.5/2,ypos-range*0.5*sqrt(3)/2,l);
        drawflakes(xpos-range*0.5/2,ypos+range*0.5*sqrt(3)/2,l);
        drawflakes(xpos+range*0.5/2,ypos+range*0.5*sqrt(3)/2,l);
    }
  }
  else {
    stroke(255);
    circle(xpos,ypos,range);
  }
}
void partytime(float x, float y, float l){
 if(l>0.00001){
    int k=13;
    rectMode(CENTER);
    if(a1==0){
    a1=random(x-k*2,x+k*2);
    a2=random(y-k*2,y+k*2);
    a3=a4=random(l-k/1.5,l+k/1.2);
    }
    a2+=0.1;
    a3-=0.04;
    a4-=0.04;
    if(a3<0) a3=0;
    if(a4<0) a4=0;
    fill(b1,b2,b3,70);
    rect(a1,a2,a3*1.8,a4*1.8);
  }
}
void glitter(float x, float y, float l){
  stroke(74,191,211);
  if(l>0.00001){
    int k=13;
    rectMode(CENTER);
    if(a1==0){
    a1=random(x-k*1,x+k*2);
    a2=random(y-k*2,y+k*2);
    a3=a4=random(l-k/1.5,l+k/1.2);
    }
    a2+=0.1;
    a3-=0.04;
    a4-=0.04;
    if(a3<0) a3=0;
    if(a4<0) a4=0;
    float hang=random(170,255);
    float glittering=random(0,1);
    if(glittering<0.1)
      fill(random(0,255),hang,hang,255);
    else
      fill(random(0,255),hang,hang,0);
 //   fill(random(128,236),255,255,70+random(-40,40));
    rect(a1,a2,a3*1.5,a4*1.5);
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
void setup(){
  size(1280,720);
  for(int i=0;i<120;i++){
    object[i]=new Snake();
  }
}
void draw(){
  background(0);
  object[cnt++]= new Snake(); cnt%=120;
  if(key=='k'){
    key='s';
    for(int i=0;i<120;i++)
      object[i].partytime(random(0,width),random(0,height),50/3);
  }
  for(int i=cnt+1;i<120;i++)
    object[i].display();
  for(int i=0;i<=cnt;i++)
    object[i].display();

}
