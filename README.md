# IoT Noise Monitoring System (ESP8266 + Firebase)

This project is an IoT-based system developed using ESP8266 and Firebase Realtime Database.  
It simulates noise level (dB) data and transmits it to the cloud in real time.

---

## 📌 Project Overview

The system generates simulated sound level values and sends them to Firebase.  
Based on a threshold value, it determines whether noise pollution exists or not.

This project demonstrates basic IoT communication, cloud integration, and embedded programming concepts.

---

## ⚙️ Features

- WiFi connection using ESP8266
- Firebase Realtime Database integration
- Real-time data transmission
- Noise level (dB) simulation
- Threshold-based status detection

---

## 🛠️ Technologies Used

- ESP8266 (NodeMCU)
- Arduino C++
- Firebase Realtime Database
- WiFi communication

---

## 📊 Working Principle

1. ESP8266 connects to WiFi  
2. Random noise level (dB) is generated  
3. Data is sent to Firebase  
4. System checks threshold (e.g. 70 dB)  
5. Status is updated (Noise / No Noise)

---

## 📁 Note

This project was developed as a student-level IoT learning project and focuses on understanding embedded systems and cloud integration basics.
