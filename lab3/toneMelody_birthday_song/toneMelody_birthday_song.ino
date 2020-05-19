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
NOTE_G4,//5  
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
NOTE_C5,//1.
NOTE_B4,//7
0,
NOTE_G4,//5
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
NOTE_D5,//2.
NOTE_C5,//1.
0,
NOTE_G4,//5
NOTE_G4,//5
NOTE_G5,//5.
NOTE_E5,//3.
NOTE_C5,//1.
NOTE_B4,//7
NOTE_A4,//6
0,
NOTE_F5,//4.
NOTE_F5,//4.
NOTE_E5,//3.
NOTE_C5,//1.
NOTE_D5,//2.
NOTE_C5,//1.
0,
};//标为0的地方不发声，表示停顿，也可以和其他音符组合用来代替简谱中的轻音和重音

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,8,4,4,4,4,
  4,
  8,8,4,4,4,4,
  4,
  8,8,4,4,4,4,2,
  8,
  8,8,4,4,4,2,
  4,
};//在这里数字代表每个音符持续的时间，数字越大持续时间越短，通常停顿时间都是倍数关系

int led1=9,led2=11,led3=3;
int bright1=29,bright2=23,bright3=19;

void setup() {
  // iterate over the notes of the melody:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);//加LED效果
}

void loop() {
  //no need to repeat the melody.

  for(int i=0;i<29;i++){
    analogWrite(led1,bright1);
    analogWrite(led2,bright2);
    analogWrite(led2,bright2);
    bright1=(bright1+11)%255;
    bright2=(bright2+17)%255;
    bright3=(bright3+23)%255;
    int noteDuration = 1000 / noteDurations[i];
    tone(8, melody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    delay(100);
  }

}
