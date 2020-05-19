//1Hz正弦波发生器
//采用DDS方法产生波形：将一个完整正弦波离散化为512个数据，存储为数组，以一个固定频率顺序读取数组的值，即可复制波形，通过改变读取的步进量，改变输出波形频率
//采用PWM进行模拟输出，约2ms的模拟转换时间，当采用频率步长为1时，一个完整波形需要512个数据，刚好是1s左右，即1Hz

#include "waveData.h"
#include "TM1637.h"
#define CLK 11
#define DIO 12
TM1637 tm1637(CLK,DIO);
int8_t displayData[4]={0x00,0x00,0x00,0x00};
 
unsigned int signalOutPWM = 3;                  //信号输出端口
unsigned int delaytime = 1950;                  //每个数据由970Hz的PWM波形滤波产生，约1.9ms延迟+其他语句延迟 约等于 2ms，足以产生两个完整PWM波形
unsigned int wholePeriodNum = 512;
unsigned int realPeriod[3]={512,2,4};
unsigned int i, freqStep;
int pp=4;
int indtype=0;

void setup() {  
  pinMode(signalOutPWM, OUTPUT);
  pinMode(4, INPUT_PULLUP);
  pinMode(7, INPUT_PULLUP);
  pinMode(8, INPUT_PULLUP);
  freqStep = 1;          
  tm1637.set();
  tm1637.init();  
}

void loop() {
  int value=digitalRead(4);
  //int value2=digitalRead(7);
  //int value3=digitalRead(8);
  if(value==LOW){
    freqStep=freqStep+1;
    if(freqStep==21)freqStep=1;
    delay(300);
  }

  wholePeriodNum=realPeriod[indtype];
  i %= wholePeriodNum;
  analogWrite(signalOutPWM, sinData[i]*pp/4);
  i += freqStep;
  displayData[2]=freqStep/10;
  displayData[3]=freqStep%10;  
  //tm1637.display(displayData);
  delayMicroseconds(5000);
  //delay(11);
}
