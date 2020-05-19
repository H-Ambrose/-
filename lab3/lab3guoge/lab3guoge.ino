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
0
};
//NOTE_C4, NOTE_G3, NOTE_G3, NOTE_A3, NOTE_G3, 0, NOTE_B3, NOTE_C4
// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {
  8,4,
  4,
  4,4,4,
  4,
  8,8,4,4,
  4,
};

int led1=9,led2=11,led3=3;
int bright1=29,bright2=23,bright3=19;

void setup() {
  // iterate over the notes of the melody:
  pinMode(led1,OUTPUT);
  pinMode(led2,OUTPUT);
  pinMode(led3,OUTPUT);
/*  
  for (int thisNote = 0; thisNote < 8; thisNote++) {

    // to calculate the note duration, take one second divided by the note type.
    //e.g. quarter note = 1000 / 4, eighth note = 1000/8, etc.
    int noteDuration = 1000 / noteDurations[thisNote];
    tone(8, melody[thisNote], noteDuration);

    // to distinguish the notes, set a minimum time between them.
    // the note's duration + 30% seems to work well:
    int pauseBetweenNotes = noteDuration * 1.30;
    delay(pauseBetweenNotes);
    // stop the tone playing:
    noTone(8);
  }
  */
}

void loop() {
  //no need to repeat the melody.

  for(int i=0;i<12;i++){
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
