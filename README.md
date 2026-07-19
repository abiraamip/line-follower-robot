# Line-Follower-Robot
## 📌 Project Overview

This project implements an autonomous line follower robot using an Arduino Nano, TB6612FNG motor driver and an 8-channel digital IR sensor array. The robot detects a black line on a white surface and follows it using a pattern-based control algorithm by adjusting the speed and direction of its motors.

## 🛠 Components Used

Arduino Nano, TB6612FNG Motor Driver, 8-Channel Digital IR Sensor Array, 2 × N20 Gear Motors, 2 × N20 Wheels, Ball Caster, 7.4V Li-Po Battery, 7.4V Li-on Battery (spare), Battery Connector, Switch, Sun Board Chassis

## ⚙ Hardware Connections

### TB6612FNG Motor Driver Connections

| TB6612FNG Pin | Arduino Nano Pin |
| ------------- | ---------------- |
| AIN1          | D4               |
| AIN2          | D5               |
| PWMA          | D9               |
| BIN1          | D6               |
| BIN2          | D7               |
| PWMB          | D10              |
| STBY          | D8               |
| VCC           | 5V               |
| GND           | GND              |
| VM            | Battery (+)      |

### IR Sensor Array Connections

| IR Sensor Pin | Arduino Nano Pin |
| ------------- | ---------------- |
| OUT1          | A0               |
| OUT2          | A1               |
| OUT3          | A2               |
| OUT4          | A3               |
| OUT5          | A4               |
| OUT6          | A5               |
| OUT7          | D11              |
| OUT8          | D12              | 
| IR            | 5V               |
| VCC           | 5V               |
| GND           | GND              |

### Motor Connections

| TB6612FNG | Motor       |
| --------- | ----------- |
| AO1 & AO2 | Right Motor |
| BO1 & BO2 | Left Motor  |

### 🔋 Battery Connections

| Battery Pin  | Connection                    |
| ------------ | ----------------------------- |
| Positive (+) | **Switch → Arduino Nano VIN** |
| Negative (−) | Arduino Nano **GND**          |

## 🔄 Working Principle

The 8-channel digital IR sensor array continuously detects the position of the black line and sends the sensor readings to the Arduino Nano.

Based on the detected sensor pattern:

* The robot moves straight when the line is centered.
* It performs slight or sharp left/right turns to stay on the line.
* If the line is lost, the robot searches in the last detected direction until the line is found again.

The process repeats continuously, allowing the robot to autonomously follow the path.

## 💻 Stages of Code Development

1. **Motor Driver Testing** – Verified the TB6612FNG motor driver by testing forward direction speed.

2. **Single IR Sensor Testing** – Tested each IR sensor individually to verify its output and ensure proper black/white detection.

3. **8-Channel IR Sensor Testing** – Read and monitored all eight sensor outputs using the Serial Monitor to identify sensor patterns.

4. **Motor Movement Testing** – Verified forward movement, left turn, right turn, spin left, spin right, and reverse operations.

5. **Pattern-Based Control** – Implemented the final pattern-based algorithm, where predefined sensor patterns control the robot's movement for straight paths, slight turns, sharp turns, junction detection, and lost-line recovery.

## 🎯 Results

- Successfully implemented a pattern-based autonomous line follower.
- Robot follows straight paths and negotiates slight and sharp turns.
- Implements lost-line recovery using the last detected direction.
- Achieved reliable line following using an 8-channel digital IR sensor array.


## 🚀 Future Improvements

- Replace the 8-channel digital IR sensor array with a curved analog IR sensor array for more precise line position detection.
- Implement a PID controller to achieve smoother steering, faster response, and better stability at higher speeds.
- Design a custom PCB to eliminate loose jumper wire connections and improve reliability.
  

<img width="953" height="981" alt="LFR_Side_View" src="https://github.com/user-attachments/assets/a903390d-69db-4990-a3d7-f103480749a1" />

<img width="961" height="850" alt="LFR_Top_View" src="https://github.com/user-attachments/assets/e5e3adb4-c93c-438e-800c-448f9f9535c1" />
