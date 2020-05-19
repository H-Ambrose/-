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
NOTE_E4,//3
NOTE_C4,//1
NOTE_E4,//3
NOTE_E4,//3
NOTE_C4,//1

NOTE_E4,//3
NOTE_E4,//3
NOTE_G4,//5
NOTE_A4,//6
NOTE_G4,//5
0,
NOTE_A4,//6
NOTE_A4,//6
NOTE_A4,//6
NOTE_G4,//5
NOTE_F4,//4
NOTE_F4,//4
NOTE_F4,//4

NOTE_D4,//2
NOTE_E4,//3
NOTE_D4,//2
NOTE_C4,//1
NOTE_D4,//2
0,

NOTE_E4,//3
NOTE_C4,//1
0,
NOTE_E4,//3
NOTE_C4,//1
0,

NOTE_E4,//3
NOTE_E4,//3
NOTE_G4,//5
NOTE_A4,//6
NOTE_A4,//6
0,
NOTE_C5,//1~
NOTE_G4,//5
NOTE_G4,//5
NOTE_A4,//6
NOTE_E4,//3

NOTE_D4,//2
NOTE_C4,//1
NOTE_D4,//2
NOTE_E4,//3
NOTE_G4,//5
0,

NOTE_C5,//1~
NOTE_G4,//5
NOTE_G4,//5
NOTE_A4,//6
NOTE_E4,//3

NOTE_D4,//2
NOTE_C4,//1
NOTE_D4,//2
NOTE_E4,//3
NOTE_C4,//1
0,
};
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
4,4,8,8,4,
8,8,8,8,4,
4,
8,8,8,8,8,8,4,
8,8,8,8,4,4,
4,8,8,4,8,8,
8,8,8,8,4,4,
4,8,8,4,4,8,8,8,8,4,4,
4,8,8,4,4,8,8,8,8,4,4
};

int led1=9,led2=11,led3=3;
int bright1=255,bright2=0,bright3=19;

void setup() {
  // iterate over the notes of the melody:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
}

void loop() {
  //no need to repeat the melody.

  for(int i=0;i<58;i++){
    analogWrite(led1,bright1);
    analogWrite(led2,bright2);
    analogWrite(led2,bright2);
    if(bright1<57) bright1+=17;
    else  bright1=(bright1-57)%255;
    bright2=(bright2+7)%255;
    bright3=(bright3+23)%255;
    int noteDuration = 1000 / noteDurations[i];
    tone(8, melody[i], noteDuration);
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    noTone(8);
    delay(100);
  }

}
