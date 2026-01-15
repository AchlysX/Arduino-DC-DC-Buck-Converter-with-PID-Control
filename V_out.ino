const int sensorPin = A0; mesurer la tension
float Vout = 0.0;
float Vin = 0.0;
float R1 = 10000.0; 
float R2 = 1000.0;   

void setup() {
    Serial.begin(9600);
}

void loop() {
    int sensorValue = analogRead(sensorPin);
    Vout = (sensorValue * 5.0) / 1023.0;  
    Vin = Vout * ((R1 + R2) / R2);       
    Serial.print("Tension mesurée: ");
    Serial.print(Vin);
    Serial.println(" V");

    delay(500);
}
