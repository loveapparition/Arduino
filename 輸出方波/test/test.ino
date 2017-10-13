uint16_t sw1 = 2;   //宣告指撥開關(調整HIGH持續時間)
uint16_t sw2 = 3;
uint16_t sw3 = 4;
uint16_t sw4 = 5;
uint16_t sw5 = 6;
uint16_t sw6 = 7;
uint16_t sw7 = 8;
uint16_t sw8 = 9;

uint16_t sw9 = 10;    //宣告指撥開關(倍數功能)
uint16_t sw10 = 11;
uint16_t sw11 = 12;

uint16_t sw12 = 15;   //宣告指撥開關(輸出波形功能)

uint8_t pin = 13;     //宣告輸出波形腳位

uint16_t cycle = 1000;    // 周期是 1000 微秒
uint16_t duty = 0;        // 高電位持續時間是 0 微秒

int val1 = 0;             // sw1指撥開關
int val2 = 0;
int val3 = 0;
int val4 = 0;
int val5 = 0;
int val6 = 0;
int val7 = 0;
int val8 = 0;

void setup() 
{
  pinMode(sw12, INPUT);     //輸出波形按鍵設為輸入
  digitalWrite(sw12,HIGH);  //開啟上拉電阻
  pinMode(pin, OUTPUT);     //輸出波形腳位設為輸出
  digitalWrite(pin, LOW);   //設定為低態電壓
}

void loop() 
{
  if(digitalRead(sw1)==HIGH)  //sw1是否接通?
    val1 = 1;
  else
    val1 = 0;
  if(digitalRead(sw2)==HIGH)  //sw2是否接通?
    val2 = 2;
  else
    val2 = 0;
  if(digitalRead(sw3)==HIGH)  //sw3是否接通?
    val3 = 4;
  else
    val3 = 0;
  if(digitalRead(sw4)==HIGH)  //sw4是否接通?
    val4 = 8;
  else
    val4 = 0;
  if(digitalRead(sw5)==HIGH)  //sw5是否接通?
    val5 = 16;
  else
    val5 = 0;
  if(digitalRead(sw6)==HIGH)  //sw6是否接通?
    val6 = 32;
  else
    val6 = 0;
  if(digitalRead(sw7)==HIGH)  //sw7是否接通?
    val7 = 64;
  else
    val7 = 0;
  if(digitalRead(sw8)==HIGH)  //sw8是否接通?
    val8 = 128;
  else
    val8 = 0;
    
  duty =val1 + val2 + val3 + val4 + val5 + val6 + val7 + val8; //總和數值

  if (digitalRead(sw9)==LOW && digitalRead(sw10)==LOW)  //如果sw9跟sw10為LOW
    duty = duty * 1;                                    //高電位持續時間*1
  if (digitalRead(sw9)==HIGH && digitalRead(sw10)==LOW) //如果sw9=HIGH和sw10為LOW
    duty = duty * 2;                                    //高電位持續時間*2
  if (digitalRead(sw9)==LOW && digitalRead(sw10)==HIGH) //如果sw9=LOW和sw10為HIGH
    duty = duty * 3;                                    //高電位持續時間*3
  if (digitalRead(sw9)==HIGH && digitalRead(sw10)==HIGH)//如果sw9=HIGH和sw10為HIGH
    duty = duty * 4;                                    //高電位持續時間*4
      
  if(digitalRead(sw12)==LOW)  //輸出波形按鈕是否按下
  {
    if(digitalRead(sw11)==LOW)  //sw11為LOW時輸出單位為微秒
    {
    digitalWrite(pin, HIGH);          //輸出HIGH
    delayMicroseconds(duty);          //輸出HIGH持續時間
    digitalWrite(pin, LOW);           //輸出LOW
    delayMicroseconds(cycle - duty);  //輸出LOW持續時間
    }
    else                              //反之輸出為毫秒
    {
    digitalWrite(pin, HIGH);          //輸出HIGH
    delay(duty);                      //輸出HIGH持續時間
    digitalWrite(pin, LOW);           //輸出LOW
    delay(cycle - duty);              //輸出LOW持續時間
    }
  }
  
}
