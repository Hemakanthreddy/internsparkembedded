# Temperature Monitoring System — InternSpark Task 1

## Objective
Read live temperature from LM35 sensor, display on 16x2 I2C LCD, 
and log readings over Serial every second.

## Hardware Used
- Arduino Uno R3
- LM35 Temperature Sensor
- 16x2 I2C LCD Display
- Breadboard + jumper wires

## Wiring Diagram

LM35:  VCC→5V, OUT→A0, GND→GND
LCD:   VCC→5V, GND→GND, SDA→A4, SCL→A5
<img width="778" height="537" alt="Screenshot 2026-07-16 143234" src="https://github.com/user-attachments/assets/f728b1c7-fce8-4f12-a805-6d2b0d443653" />



## How It Works
1. LM35 outputs 10mV per °C as analog voltage.
2. Arduino reads this via analogRead(A0) and converts to °C.
3. Value is displayed on LCD, refreshed continuously.
4. Every 1 second, reading is also printed to Serial Monitor for logging.

## Demo and Report
https://drive.google.com/drive/folders/1Pq10raCweL3mtMODlF8-4UBel3AF8rnn?usp=sharing
## images
<img width="1600" height="1200" alt="WhatsApp Image 2026-07-16 at 2 29 19 PM" src="https://github.com/user-attachments/assets/3e1b276a-880e-442b-a2d8-80b59da37ce5" />

## video 


https://github.com/user-attachments/assets/f488a5ce-6b50-49a5-a0f6-47b8f7c6d578



