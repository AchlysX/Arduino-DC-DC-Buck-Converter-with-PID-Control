const int pwmPin = 3; 
int dutyCycle = 128;

void setup() {
    pinMode(pwmPin, OUTPUT);
}

void loop() {
    analogWrite(pwmPin, dutyCycle); 
    delay(100);
}
