# Arduino DC-DC Buck Converter (PWM + PID)

This project explores a DC-DC **buck (step-down) converter** controlled by an Arduino Uno, with a PID loop to regulate the output voltage. 
It was developed and validated in simulation (Tinkercad) as part of a microcontroller project report.

## What’s in this repo

- `Pid_reg.ino`: Closed-loop regulation using a PID controller that adjusts PWM from voltage feedback.
- `V_out.ino`: Voltage measurement sketch (reads analog input and reconstructs voltage using a divider formula).
- `B_pwm.ino`: Manual PWM duty-cycle stepping using a push-button. 
- `PWM_Ctrl.ino`: Simple fixed-duty PWM output test.
- `Projet-M.C-Rapport.pdf`: Full report (French) explaining PWM, the buck concept, and simulation results. 

## Hardware / wiring (Arduino Uno)

Default pin mapping used in the sketches:
- PWM output (MOSFET gate drive): `D3`. 
- Voltage feedback ADC: `A0`. 
- Button input (manual PWM sketch): `D2` with `INPUT_PULLUP`. 

Filter/component values reported from the simulation sizing:
- Capacitor: `100 µF`, Inductor: `50 mH`, Load: `10 kΩ`.  

## PID sketch details

The PID sketch targets a setpoint of `5.0 V` and prints measured voltage and PWM output over Serial.  
Default gains in `Pid_reg.ino`: `Kp=1.0`, `Ki=0.1`, `Kd=0.01`. 

Dependency:
- Arduino PID library (Brett Beauregard style), since the code uses `PID myPID(...)` / `Compute()` / `SetMode(AUTOMATIC)`. 

## How to run

1. Open the desired `.ino` file in Arduino IDE.
2. Select **Arduino Uno** and the correct COM port.
3. Upload.
4. Open Serial Monitor (for `Pid_reg.ino` / `V_out.ino`) at `9600` baud. 

## Authors

- Oumaima Berkani - berk.oumaima@gmail.com 
- Ahmed Benlafqih.   
