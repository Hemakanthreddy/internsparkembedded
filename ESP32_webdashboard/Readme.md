# ESP32 Web Dashboard with Live Sensor Monitoring

## Project Overview

This project creates a simple web-based dashboard hosted on an ESP32. The dashboard displays live temperature and humidity readings from a DHT11 sensor and allows users to control an LED through a web browser. The ESP32 acts as a web server, making the dashboard accessible from any device connected to the same Wi-Fi network.

---

## Features

* Live temperature monitoring.
* Live humidity monitoring.
* Web-based LED ON/OFF control.
* Automatic sensor updates every 2 seconds.
* Mobile-friendly dashboard.
* No external web server required.

---

## Hardware Required

* ESP32 Development Board
* DHT11 Sensor
* LED (or Relay Module)
* 220 Ω Resistor (for external LED, if used)
* Breadboard
* Jumper Wires
* USB Cable

---
## images
<img width="1536" height="1024" alt="ChatGPT Image Jul 24, 2026, 06_45_14 PM" src="https://github.com/user-attachments/assets/4bda322b-748b-4ec5-87e9-772980914de7" />


## Software Requirements

* Arduino IDE
* ESP32 Board Package
* WiFi Library
* WebServer Library
* DHT Sensor Library
* Adafruit Unified Sensor Library

---

## Pin Connections

### DHT11

| DHT11 | ESP32 |
| ----- | ----- |
| VCC   | 3.3V  |
| GND   | GND   |
| DATA  | GPIO4 |

### LED

| LED      | ESP32                        |
| -------- | ---------------------------- |
| Positive | GPIO2                        |
| Negative | GND (through 220 Ω resistor) |

---

## Working Principle

1. ESP32 connects to the configured Wi-Fi network.
2. A web server starts on port 80.
3. Visiting the ESP32 IP address opens the dashboard.
4. The dashboard requests new sensor readings every two seconds.
5. Temperature and humidity values are displayed without refreshing the page.
6. Pressing the **Toggle LED** button changes the LED state instantly.

---

## Expected Output

The dashboard displays:

* Temperature (°C)
* Humidity (%)
* LED Toggle Button

Open the Serial Monitor after uploading the sketch to view the ESP32 IP address. Enter this IP address in any web browser connected to the same Wi-Fi network.

---

## Applications

* Smart Home Monitoring
* IoT Sensor Dashboard
* Remote Device Control
* Home Automation
* Environmental Monitoring
* Industrial Monitoring

---

## Future Improvements

* Add multiple sensors.
* Display historical graphs.
* Control multiple relays.
* Add user authentication.
* Store sensor data in a cloud database.
* Enable remote internet access using MQTT or Firebase.

---

## Conclusion

This project demonstrates how an ESP32 can function as a standalone web server for IoT applications. It provides live environmental monitoring and remote device control through a responsive web dashboard, making it a strong foundation for smart home and industrial automation projects.
