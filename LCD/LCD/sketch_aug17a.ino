
/*
LCD  Arduino
PIN1 = GND
PIN2 = 5V
RS(CS) = 8; 
RW(SID)= 9; 
EN(CLK) = 3;
PIN15 PSB = GND;
*/

#include <LCD12864RSPI.h>
#define AR_SIZE( a ) sizeof( a ) / sizeof( a[0] )

unsigned char show0[]="2017/08/18";                    //皜祈岫
unsigned char show1[]="geek-workshop";
int key[16];
int num=0;
int i;
void setup()
{
  Serial.begin(9600);
  LCDA.Initialise(); // 撅�����
  
 LCDA.DisplayString(0,0 ,show0,AR_SIZE(show0));
 LCDA.WriteCommand(0x90);
  

  delay(100);
}

void loop()
{
  
  if(Serial.available())
  {
    key[num]=Serial.read();
    if(key[num]=='-')
    {
      LCDA.WriteCommand(0x90);
      for(i=0;i<16;i++)
      {
        LCDA.WriteData(32);
        key[i]=' ';
      }
      LCDA.WriteCommand(0x90);
      num=0;
    }
    else
    {
      LCDA.WriteData(key[num]);
      num++;
      if(num>15)
      {
        LCDA.WriteCommand(0x90);
        num=0;
      }
    }   
  }
}
  

