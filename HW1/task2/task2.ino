#define R1 1000
#define V_IN 5

int sensorValue = 0;
float Vout = 0;
float R2 = 0;
float buffer = 0;

void setup() {
    Serial.begin(9600);
}

void loop() {
    sensorValue = analogRead(A0);
    if (sensorValue) {
        Vout = (sensorValue * V_IN)/1023.0;
        R2 = R1 * ((V_IN/Vout) - 1);
        Serial.print("Resistance: ");
        Serial.print(R2);
        Serial.println("Ohms");
        delay(1000);
    }
}