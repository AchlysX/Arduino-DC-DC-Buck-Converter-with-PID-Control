#include <PID_v1.h>

const int pwmPin = 3;
const int sensorPin = A0;
double Setpoint = 5.0; 
double Input, Output;
double Kp = 1.0, Ki = 0.1, Kd = 0.01; 

PID myPID(&Input, &Output, &Setpoint, Kp, Ki, Kd, DIRECT);

void setup() {
    pinMode(pwmPin, OUTPUT);
    Serial.begin(9600);
    myPID.SetMode(AUTOMATIC);
}

void loop() {
    int sensorValue = analogRead(sensorPin);
    Input = (sensorValue * 5.0) / 1023.0;  

    myPID.Compute();  
    analogWrite(pwmPin, Output);  

    Serial.print("Tension mesurée: ");
    Serial.print(Input);
    Serial.print(" V - PWM: ");
    Serial.println(Output);

    delay(100);
}
