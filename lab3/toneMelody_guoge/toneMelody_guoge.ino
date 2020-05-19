/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/Tone
*/

#include "pitches.h"

// notes in the melody:
int melody[] = {
NOTE_G3,//5  
NOTE_C4,//1
0,
NOTE_C4,//1
NOTE_C4,//1
NOTE_C4,//1.
NOTE_G3,//5
NOTE_A3,//6
NOTE_B3,//7
NOTE_C4,//1
NOTE_C4,//1
0,
NOTE_E4,//3
NOTE_C4,//1
NOTE_D4,//2
NOTE_E4,//3
NOTE_G4,//5
NOTE_G4,//5

NOTE_E4,//3
0,
NOTE_E4,//3
NOTE_C4,//1
0,
NOTE_E4,//3
NOTE_G4,//5
0,
NOTE_E4,//3
NOTE_D4,//2
NOTE_D4,//2
0,
NOTE_A4,//6
NOTE_G4,//5
NOTE_D4,//2
NOTE_E4,//3

NOTE_G4,//5
NOTE_E4,//3
0,
NOTE_G4,//5

NOTE_E4,//3
NOTE_D4,//2
NOTE_E4,//3
NOTE_C4,//1
NOTE_E4,//3
0,

NOTE_G3,//5 每
0,
NOTE_A3,//6 个
NOTE_C4,//1 人
NOTE_C4,//1 被
NOTE_E4,//3 迫
0,
NOTE_E4,//3 着
NOTE_G4,//5 发
NOTE_G4,//5 出
NOTE_D4,//2 最
NOTE_D4,//2 后
NOTE_D4,//2 的
NOTE_A3,//~6 吼
NOTE_D4,//2 声
0
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,4,
  3,
  4,3,4,
  8,
  8,8,3,3,
  4,
  4,4,8,8,2,2,
  2,4,4,2,4,4,2,4,4,2,2,
  2,
  2,2,2,2,
  4,4,4,4,
  8,16,16,2,
  2,
  2,4,4,4,4,2,4,4,4,4,
  4,8,8,2,2,2
};

int led1=9,led2=11,led3=3;
int bright1=255,bright2=0,bright3=19;

void setup() {
  // iterate over the notes of the melody:
}

void loop() {
  //no need to repeat the melody.

  for(int i=0;i<60;i++){
    analogWrite(led1,bright1);
    analogWrite(led2,bright2);
    analogWrite(led2,bright2);
    int noteDuration = 1000 / noteDurations[i];
    tone(8, melody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    delay(100);
  }
}
