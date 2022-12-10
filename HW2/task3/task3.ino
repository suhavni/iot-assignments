#define BUZZER A2
#define HIGH 255

int lastHuman = 0;
int previouslyHuman = false;

void setup() {
	Serial.begin(9600);
    pinMode(BUZZER, OUTPUT);
}

void loop() {
    int sensorValue = analogRead(A0);
    int currentMillis = millis();
    Serial.println(sensorValue);
    if (sensorValue && sensorValue < 30) {
        analogWrite(BUZZER, (currentMillis - lastHuman < 2000) ? HIGH : LOW
        );
        previouslyHuman = true;
    } else if (previouslyHuman) {
        previouslyHuman = false;
        lastHuman = currentMillis;
    } else if (currentMillis - lastHuman > 2000) {
        analogWrite(BUZZER, LOW);
    } 
}
