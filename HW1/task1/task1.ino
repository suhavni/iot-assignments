unsigned long startedOn = 0;
long interval = 1;
int currentLED = 12;
int nextLED = 2;

void setup() {
  startedOn = millis();
  for (int i = 2; i <= 12; i+=2) {
    pinMode(i, OUTPUT);
  }
}

void loop() {
  int sensorValue = analogRead(A0);
  
  unsigned long currentMillis = millis();

  nextLED = (sensorValue < 512) ? -2 : 2;
  sensorValue = (sensorValue < 512) ? sensorValue : 1023 - sensorValue;
  interval = (sensorValue+15)*2;
  
  if(currentMillis - startedOn > interval) {
    startedOn = currentMillis;
    digitalWrite(currentLED+2, LOW);
    currentLED = (currentLED + nextLED + 12)%12;
    digitalWrite(currentLED+2, HIGH);
  }
}
