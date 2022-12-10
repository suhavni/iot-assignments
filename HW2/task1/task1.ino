#include "pitches.h"

int buttons[] = { 2, 3, 4, 5 };
int buzzer = 8;
unsigned long lastPlayedNote = 0;
int notes[] = {
  NOTE_C4, NOTE_D4, NOTE_E4, NOTE_G4
};

void setup() {
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
