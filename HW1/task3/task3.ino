int coins = 0;

void setup() {
	Serial.begin(9600);
}

void loop() {
	int sensorValue = analogRead(A0);
    if (sensorValue && sensorValue < 200) {
        Serial.print("Coins: ");
        Serial.println(++coins);
        delay(30);
    }
}
