int button=2;
int led[]={3,4,5};
int type=3;
int buttonstate=0;
int time2=100;
int time3=50;

void setup() 
{
 pinMode(button,INPUT);
 for(int i=0;i<3;i++)
 {
   pinMode(led[i],OUTPUT);
 }  
}

void loop() 
{
 if(button == HIGH)
 {
   delay(1000);
   if(button == HIGH)
   {
    buttonstate = buttonstate + 1;  
   } 
 } 
 if(buttonstate > type)
 {
   buttonstate=0;
 }
  
 switch (buttonstate) 
 {
 case 1://全亮
  for(int a=0;a<3;a++)
  {
    analogWrite(led[a],255);
  }
 break;
 
 case 2://亮滅
  for(int a=0;a<3;a++)
  {
    analogWrite(led[a],255);
    delay(time2);
    analogWrite(led[a],0);
  }  
 break;
 
 case 3://亮慢慢滅
  for(int a=0;a<3;a++)
  {
    for(int light=0;light<=255;light=light+15)
    {
    analogWrite(led[a],light);
    delay(time3);
    }
    for(int light=255;light>=0;light=light-5)
    {
    analogWrite(led[a],light);
    delay(time3);
    }
  }  
 break;
 
 default: //全滅
  for(int a=0;a<3;a++)
  {
    analogWrite(led[a],0);
  }
 }
}
