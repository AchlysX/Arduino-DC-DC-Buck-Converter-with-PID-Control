const int pwmPin = 3;
const int buttonPin = 2;
int dutyCycle = 128;  
void setup() {
    pinMode(pwmPin, OUTPUT);
    pinMode(buttonPin, INPUT_PULLUP);
}

void loop() {
    if (digitalRead(buttonPin) == LOW) {
        dutyCycle += 25;
        if (dutyCycle > 255) dutyCycle = 0;
        delay(200);
    }
    
    analogWrite(pwmPin, dutyCycle);
}
