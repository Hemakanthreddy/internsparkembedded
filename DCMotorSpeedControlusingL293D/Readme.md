# DC Motor Speed Control Using PWM with Obstacle Detection

## Project Overview

This project controls the speed of a DC motor using Pulse Width Modulation (PWM) on an Arduino UNO. An HC-SR04 ultrasonic sensor continuously measures the distance to nearby objects. If an obstacle is detected within a predefined distance (15 cm), the Arduino immediately stops the motor. When the obstacle is removed, the motor automatically resumes running at the selected PWM speed.

---

## Objectives

* Control DC motor speed using PWM.
* Detect obstacles using an HC-SR04 ultrasonic sensor.
* Automatically stop the motor when an obstacle is detected.
* Resume motor operation when the path is clear.

---

## Components Required

* Arduino UNO
* L293D Motor Driver IC
* Toy DC Motor (3–6 V)
* HC-SR04 Ultrasonic Sensor
* Breadboard
* Jumper Wires
* USB Cable (Power Supply)

> **Note:** No external battery is required for this demonstration when using a small toy DC motor.

---

## Software Requirements

* Arduino IDE
* Arduino UNO Board Package

---

## Pin Connections

### Arduino to L293D

| Arduino Pin | L293D Pin         | Function          |
| ----------- | ----------------- | ----------------- |
| D9          | EN1 (Pin 1)       | PWM Speed Control |
| D8          | IN1 (Pin 2)       | Motor Direction   |
| D7          | IN2 (Pin 7)       | Motor Direction   |
| 5V          | VCC1 (Pin 16)     | Logic Supply      |
| 5V          | VCC2 (Pin 8)      | Motor Supply      |
| GND         | Pins 4, 5, 12, 13 | Ground            |

### Arduino to HC-SR04

| Arduino Pin | HC-SR04 Pin |
| ----------- | ----------- |
| D10         | TRIG        |
| D11         | ECHO        |
| 5V          | VCC         |
| GND         | GND         |

### Motor Connection

* L293D Pin 3 (OUT1) → Motor Terminal 1
* L293D Pin 6 (OUT2) → Motor Terminal 2

---

## Working Principle

1. The Arduino generates a PWM signal on pin D9 to control the motor speed.
2. The HC-SR04 measures the distance to nearby objects.
3. If the measured distance is greater than 15 cm, the motor runs at the selected PWM speed.
4. If the distance is 15 cm or less, the Arduino sets the PWM value to zero, stopping the motor.
5. Once the obstacle moves away, the motor automatically resumes operation.

---
## circuit
<img width="1536" height="1024" alt="ChatGPT Image Jul 24, 2026, 06_28_53 PM" src="https://github.com/user-attachments/assets/44220a5c-38eb-46f0-acb0-83262075789f" />

## Sample Results

| Distance (cm) | Motor Status |
| ------------- | ------------ |
| 50            | Running      |
| 30            | Running      |
| 20            | Running      |
| 15            | Stopped      |
| 10            | Stopped      |
| 5             | Stopped      |

---
## images
<img width="899" height="1599" alt="WhatsApp Image 2026-07-24 at 6 23 39 PM" src="https://github.com/user-attachments/assets/5b706618-ad6c-4c42-aed5-24eb7ad08f7e" />
## video 


https://github.com/user-attachments/assets/ad21a50d-387b-422c-930a-680175f000bd



## Applications

* Obstacle Avoidance Systems
* Smart Robotic Vehicles
* Automatic Conveyor Systems
* Industrial Safety Systems
* Autonomous Mobile Robots

---

## Future Improvements

* Add an LCD or OLED display to show the measured distance.
* Use a buzzer or LED to indicate obstacle detection.
* Implement variable motor speed based on obstacle distance.
* Upgrade to an ESP32 for wireless monitoring and control.

---

## Conclusion

This project successfully demonstrates PWM-based DC motor speed control combined with ultrasonic obstacle detection using an Arduino UNO and an L293D motor driver. The system provides automatic motor stopping when an obstacle is detected within the defined range, making it suitable for basic automation and robotics applications. It is a simple, low-cost project that introduces key embedded systems concepts, including PWM motor control, sensor interfacing, and real-time decision-making.
