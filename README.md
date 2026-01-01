# 🔌 UbiqIotos - ESP8266 WiFi LED Control System

[![IoT](https://img.shields.io/badge/IoT-ESP8266-blue?style=for-the-badge&logo=arduino)](https://github.com/sismadi/iot)
[![WiFi](https://img.shields.io/badge/WiFi-Enabled-green?style=for-the-badge&logo=wifi)](https://github.com/sismadi/iot)
[![REST API](https://img.shields.io/badge/REST-API-orange?style=for-the-badge&logo=fastapi)](https://github.com/sismadi/iot)

## 📝 Deskripsi Proyek

Proyek IoT menggunakan **ESP8266 (D1 Mini)** untuk mengontrol LED melalui REST API. Sistem ini memungkinkan kontrol LED secara remote melalui WiFi dengan autentikasi API key, mendukung metode GET dan POST dengan CORS headers untuk integrasi web application.

### ✨ Fitur Utama
- 📡 **WiFi Control** - Kontrol perangkat dari mana saja via WiFi
- 🔐 **API Security** - Proteksi dengan API Key authentication
- 🔄 **REST API** - GET & POST endpoints dengan JSON response
- 💡 **LED Control** - On/Off control dengan status feedback

## 🎥 Video Demonstrasi

Klik gambar di bawah untuk menonton video demonstrasi lengkap:

[![Video Demonstrasi ESP8266](https://img.youtube.com/vi/VIDEO_ID/maxresdefault.jpg)](https://www.youtube.com/watch?v=VIDEO_ID)

> **📌 Catatan:** Ganti `VIDEO_ID` dengan ID video YouTube Anda

## 🚀 Cara Menggunakan

### Hardware Setup
1. Hubungkan ESP8266 D1 Mini via USB

### Software Setup
2. Install Arduino IDE dan library berikut:
   - ESP8266WiFi
   - ESP8266WebServer
   - ArduinoJson

3. Clone repository ini:
```bash
git clone https://github.com/sismadi/iot.git
```

4. Konfigurasi WiFi dan API Key:
```cpp
const char* WIFI_SSID = "YourWiFiSSID";
const char* WIFI_PASS = "YourPassword";
const char* API_KEY   = "YourSecretKey";
```

5. Upload sketch ke ESP8266

6. Buka Serial Monitor untuk mendapatkan IP address

### Testing API

**GET Method:**
```bash
curl "http://<ESP_IP>/api/led?state=on&key=rahasiaku123"
```

**POST Method:**
```bash
curl -X POST http://<ESP_IP>/api/led \
  -H "X-API-Key: rahasiaku123" \
  -H "Content-Type: application/json" \
  -d '{"state":"on"}'
```

## ⚙️ Teknologi yang Digunakan

- **Hardware:**
  - ESP8266 D1 Mini
  - Built-in LED (GPIO2)

- **Software:**
  - Arduino C++
  - ESP8266WebServer Library
  - ArduinoJson Library
  - REST API Architecture

- **Features:**
  - WiFi Connectivity
  - HTTP Server
  - CORS Support
  - API Key Authentication

## 📡 API Endpoints

| Method | Endpoint | Description |
|--------|----------|-------------|
| GET | `/ping` | Health check |
| GET | `/api/led?state=on&key=xxx` | Turn LED on/off |
| POST | `/api/led` | Turn LED on/off (JSON body) |

## 🎓 Informasi Pengembang

- **Nama:** [Nama Anda]
- **NIM:** [NIM Anda]
- **Mata Kuliah:** Internet of Things (IoT)
- **Semester:** 5
- **GitHub Repository:** [github.com/sismadi/iot](https://github.com/sismadi/iot)

## 📄 Lisensi

MIT License - Feel free to use this project for learning purposes

---

**⭐ Jika project ini membantu, jangan lupa untuk memberikan star!**
