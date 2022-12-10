/*
  Melody

  Plays a melody

  circuit:
  - 8 ohm speaker on digital pin 8

  created 21 Jan 2010
  modified 30 Aug 2011
  by Tom Igoe

  This example code is in the public domain.

  https://www.arduino.cc/en/Tutorial/BuiltInExamples/toneMelody
*/

#include "pitches.h"

// notes in the melody:
int buttons[] = { 2, 3, 4, 5 };
int buzzer = 8;
unsigned long lastPlayedNote = 0;
int notes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4
};

void setup() {
  // iterate over the notes of the melody:
  lastPlayedNote = millis();
  for (int i = 0; i <= 3; i++) {
    pinMode(buttons[i], INPUT_PULLUP);
  }
}

void loop() {
  for (int i = 0; i <= 3; i++) {
    bool activated = false;
    while(digitalRead(buttons[i]) == LOW) {
      tone(buzzer, notes[i]);
      activated = true;
      lastPlayedNote = millis();
    }
  }
  unsigned long currentMillis = millis();
  if (abs(currentMillis - lastPlayedNote) >= 500) {
    noTone(buzzer);
    lastPlayedNote = currentMillis;
  }
}
