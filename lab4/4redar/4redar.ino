#include "pitches.h"

int melody[]={
  NOTE_C1,
  NOTE_D2,
  NOTE_E4,
  NOTE_F6,
  NOTE_C8
  };
int noteDuration=500;
int shortDuration=200;

void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  int sensorValue = analogRead(A0);
  float voltage = sensorValue * (5.0 / 1023.0);
  //test output检验输出电压:
  Serial.println(voltage);

  //随着亮度降低，蜂鸣器发出的音调逐渐升高
  //在亮度很低的情况下，设置使蜂鸣器发出急促高音
  if(voltage>=0&&voltage<1){
    tone(8,melody[0],noteDuration);
    Serial.println("dim light");
  }
  else if(voltage>=1 &&voltage<2){
    tone(8,melody[1],noteDuration);
  }
  else if(voltage>=2 &&voltage<3){
    tone(8,melody[2],noteDuration);
  }
  else if(voltage>=3 &&voltage<4){
    tone(8,melody[3],noteDuration);
  }
  else {
    for(int i=0;i<9;++i){
      tone(8,melody[4],shortDuration);
      delay(400);
    }
  }
  noTone(8);
  delay(1000);
}
