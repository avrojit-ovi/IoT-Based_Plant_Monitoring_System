# IoT-Based Plant Monitoring System

<div align="center">

[![GitHub License](https://img.shields.io/badge/license-MIT-blue.svg)](LICENSE)
[![GitHub Issues](https://img.shields.io/github/issues/avrojit-ovi/IoT-Based_Plant_Monitoring_System)]()
[![GitHub Stars](https://img.shields.io/github/stars/avrojit-ovi/IoT-Based_Plant_Monitoring_System)]()
[![Repository Size](https://img.shields.io/github/repo-size/avrojit-ovi/IoT-Based_Plant_Monitoring_System)]()

An intelligent IoT-based system for real-time plant health monitoring with cloud connectivity and mobile application support.

[Features](#features) • [Installation](#installation) • [Usage](#usage) • [Architecture](#system-architecture) • [Documentation](#documentation)

</div>

---

## 📋 Table of Contents

- [Overview](#overview)
- [Features](#features)
- [System Architecture](#system-architecture)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation Guide](#installation-guide)
- [Usage Instructions](#usage-instructions)
- [Project Structure](#project-structure)
- [Configuration](#configuration)
- [API Documentation](#api-documentation)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

---

## 🌿 Overview

The **IoT-Based Plant Monitoring System** is a comprehensive solution designed to monitor plant health parameters in real-time using IoT sensors and microcontroller technology. This system collects critical environmental and plant health data, processes it, and provides actionable insights through a user-friendly interface.

This project combines embedded systems programming with IoT cloud connectivity to enable remote plant monitoring and automated care recommendations. Whether you're managing a small home garden or a large agricultural operation, this system provides the tools needed to maintain optimal plant health.

### Key Benefits

- **Real-Time Monitoring**: Track plant health metrics 24/7
- **Remote Access**: Monitor your plants from anywhere via web or mobile app
- **Data Analytics**: Historical data analysis for better plant care
- **Alert System**: Receive notifications when plants need attention
- **Automated Responses**: Optional automated watering and lighting controls
- **User-Friendly Dashboard**: Intuitive interface for easy monitoring

---

## ✨ Features

### Core Monitoring Capabilities

- **Soil Moisture Detection**: Real-time soil moisture level monitoring
- **Temperature Sensing**: Ambient and soil temperature tracking
- **Humidity Monitoring**: Environmental humidity measurement
- **Light Intensity Analysis**: Photosynthesis efficiency optimization
- **pH Level Detection**: Soil pH monitoring for optimal nutrient absorption
- **Nutrient Level Tracking**: NPK (Nitrogen, Phosphorus, Potassium) measurement

### Data Management & Connectivity

- **Cloud Integration**: Seamless data synchronization with cloud servers
- **Data Logging**: Comprehensive historical data storage
- **Real-Time Sync**: Instant data transmission via WiFi/Bluetooth
- **Multiple Device Support**: Connect and monitor multiple plants simultaneously
- **Data Export**: Export monitoring data in various formats (CSV, JSON)

### User Interface & Accessibility

- **Web Dashboard**: Browser-based monitoring interface
- **Mobile Application (Botanica)**: Dedicated mobile app for iOS and Android
- **Real-Time Alerts**: Instant notifications via push, email, and SMS
- **Visual Analytics**: Charts and graphs for trend analysis
- **Customizable Thresholds**: Set custom alert limits for each plant

### Advanced Features

- **Machine Learning Integration**: Predictive plant health analysis
- **Weather Integration**: Real-time weather data for better plant care
- **Watering Schedule Optimization**: Intelligent watering recommendations
- **Multi-Language Support**: Interface available in multiple languages
- **Energy Efficient**: Low-power sensor operation for extended battery life

---

## 🏗️ System Architecture

### High-Level Architecture Diagram

```
┌─────────────────────────────────────────────────────────────┐
│                    Cloud Platform / Server                   │
│              (Data Storage & Processing Backend)             │
└──────────────────────┬──────────────────────────────────────┘
                       │
        ┌──────────────┼──────────────┐
        │              │              │
    ┌───▼───┐     ┌────▼────┐   ┌──▼────┐
    │  Web  │     │ Mobile  │   │ Alert │
    │Dashboard   │ App      │   │System  │
    └───────┘     └─────────┘   └───────┘
        │              │              │
        └──────────────┼──────────────┘
                       │
        ┌──────────────▼──────────────┐
        │   WiFi/Bluetooth Gateway    │
        │    (ESP32/Arduino Based)    │
        └──────────────┬──────────────┘
                       │
        ┌──────────────┼──────────────┐
        │              │              │
    ┌───▼───┐     ┌────▼────┐   ┌──▼────┐
    │ Soil  │     │Temperature   │ Light │
    │Moisture   │ & Humidity    │Sensor │
    │Sensor │   │ Sensor       │      │
    └───────┘   └──────────┘   └──────┘
```

### Component Breakdown

1. **Sensor Layer**: Collects environmental and plant health data
2. **Microcontroller Layer**: Processes sensor data and manages communication
3. **Connectivity Layer**: Manages WiFi/Bluetooth transmission
4. **Cloud Layer**: Stores and processes data
5. **Application Layer**: User interfaces for monitoring and control

---

## 🛠️ Hardware Requirements

### Essential Components

| Component | Model | Quantity | Purpose |
|-----------|-------|----------|---------|
| Microcontroller | ESP32 / Arduino | 1 | Main processing unit |
| Soil Moisture Sensor | Capacitive/Resistive | 1 | Soil moisture measurement |
| Temperature Sensor | DHT22 / DS18B20 | 1 | Temperature monitoring |
| Humidity Sensor | Built-in DHT22 | 1 | Environmental humidity |
| Light Sensor | LDR / BH1750 | 1 | Light intensity detection |
| Water Pump (Optional) | 3-6V DC Motor | 1 | Automated watering |
| Relay Module | 2-Channel 5V | 1 | Pump/Light control |
| Breadboard & Jumper Wires | - | As needed | Component connections |
| USB Cable | Type A-B | 1 | Programming & power |
| Power Supply | 5V USB / Battery | 1 | System power |

### Optional Components

- **pH Sensor**: For soil acidity monitoring
- **EC/NPK Sensor**: For nutrient level detection
- **Cloud Storage Device**: For local backup
- **LCD Display**: For local data visualization
- **OLED Screen**: For compact display option
- **Solar Panel**: For sustainable power supply
- **LiPo Battery**: For wireless operation

### Schematic Design

Refer to `Untitled Sketch.fzz` (Fritzing file) and `schematic design 1.png` for detailed circuit connections and wiring diagrams.

---

## 💻 Software Requirements

### Development Environment

- **Arduino IDE** (v1.8.x or higher)
- **Python** (v3.8 or higher)
- **Node.js** (v14 or higher) - for backend services
- **MongoDB** or **Firebase** - for database

### Libraries & Dependencies

#### Arduino Libraries
```
- WiFi.h (built-in for ESP32)
- DHT.h (DHT sensor library)
- Wire.h (I2C communication)
- EEPROM.h (Data storage)
- ArduinoJson.h (JSON parsing)
```

#### Python Libraries
```
- requests
- pymongo
- numpy
- pandas
- matplotlib
- flask
```

#### JavaScript Libraries
```
- Express.js
- Socket.io
- MongoDB Driver
- Chart.js
```

### Required Accounts & Services

- **Firebase Project** (or alternative cloud service)
- **Gmail Account** (for email notifications)
- **Twilio Account** (for SMS alerts, optional)
- **OpenWeatherMap API Key** (for weather data)

---

## 📦 Installation Guide

### Step 1: Hardware Assembly

1. **Prepare the Microcontroller**
   ```bash
   - Install Arduino IDE
   - Connect ESP32/Arduino to your computer via USB
   - Install board drivers and libraries
   ```

2. **Connect Sensors**
   - Follow the circuit diagram in `schematic design 1.png`
   - Use the Fritzing file `Untitled Sketch.fzz` for reference
   - Double-check all connections before powering on

3. **Assemble the Housing** (Optional)
   - Mount sensors in waterproof enclosure
   - Ensure proper ventilation for humidity sensor
   - Protect electronics from water splash

### Step 2: Firmware Installation

1. **Clone the Repository**
   ```bash
   git clone https://github.com/avrojit-ovi/IoT-Based_Plant_Monitoring_System.git
   cd IoT-Based_Plant_Monitoring_System
   ```

2. **Install Arduino Libraries**
   - Open Arduino IDE
   - Go to Sketch → Include Library → Manage Libraries
   - Install required libraries from the `libraries` folder

3. **Configure WiFi & Cloud Settings**
   ```cpp
   // Edit the configuration file with your WiFi credentials
   const char* ssid = "YOUR_SSID";
   const char* password = "YOUR_PASSWORD";
   const char* firebase_url = "YOUR_FIREBASE_URL";
   const char* firebase_key = "YOUR_FIREBASE_KEY";
   ```

4. **Upload Firmware**
   - Open the main sketch from `iot_based_plant_monitoring_system` folder
   - Select the correct board (ESP32 or Arduino)
   - Choose the correct COM port
   - Click Upload

### Step 3: Mobile App Installation

1. **Install Botanica App**
   - Download from Google Play Store or Apple App Store
   - Or build from source: `botanica` folder
   - Follow in-app setup wizard

2. **Configure App Settings**
   - Create account or login
   - Add your device
   - Set plant type and care requirements
   - Configure notification preferences

### Step 4: Cloud Setup

1. **Firebase Configuration**
   ```bash
   npm install -g firebase-tools
   firebase init
   firebase deploy
   ```

2. **Database Setup**
   ```bash
   - Create Realtime Database in Firebase
   - Set up authentication rules
   - Create collections for users, devices, and sensor data
   ```

3. **Backend API Setup**
   ```bash
   cd backend
   npm install
   npm start
   ```

---

## 📱 Usage Instructions

### First-Time Setup

1. **Power On the Device**
   - Connect USB power or battery
   - LED should blink indicating system initialization
   - Wait 30 seconds for WiFi connection

2. **Connect to WiFi**
   - Device will broadcast an AP (Access Point)
   - Connect from mobile phone
   - Enter WiFi credentials through setup page
   - Device will restart and connect to network

3. **Register Plant Profile**
   - Open Botanica app
   - Create new plant entry
   - Select plant type from database
   - Set optimal care parameters
   - Input device pairing code

### Daily Monitoring

#### Via Web Dashboard
```
1. Open browser → Navigate to dashboard URL
2. Login with your credentials
3. View real-time sensor readings
4. Check historical graphs and trends
5. Download data reports
```

#### Via Mobile App
```
1. Open Botanica app
2. View dashboard with all connected plants
3. Tap plant for detailed metrics
4. Check alerts and recommendations
5. Set watering or lighting schedules
```

### Data Interpretation

#### Soil Moisture Levels
- **0-30%**: Dry - Water needed
- **30-60%**: Optimal - Normal range
- **60-100%**: Wet - Reduce watering

#### Temperature Range
- **Below 15°C**: Too cold for most plants
- **15-25°C**: Optimal range
- **Above 30°C**: Heat stress risk

#### Humidity Levels
- **30-50%**: Low - Increase misting
- **50-70%**: Optimal range
- **Above 70%**: High - Risk of fungal growth

#### Light Intensity
- **0-500 lux**: Low light
- **500-2500 lux**: Medium light
- **2500+ lux**: Bright light

### Setting Up Alerts

1. **Mobile App Alerts**
   - Tap Settings → Notifications
   - Enable/disable alert types
   - Set moisture threshold (%)
   - Set temperature range (°C)
   - Save preferences

2. **Email Notifications**
   - Settings → Email Preferences
   - Enter email address
   - Select alert frequency
   - Choose notification types

3. **Scheduled Actions**
   - Set automatic watering schedule
   - Configure grow light timing
   - Enable/disable based on humidity
   - Save automation rules

---

## 📁 Project Structure

```
IoT-Based_Plant_Monitoring_System/
│
├── botanica/                           # Mobile Application
│   ├── ios/                            # iOS app source code
│   ├── android/                        # Android app source code
│   ├── lib/                            # Shared libraries
│   ├── assets/                         # Images and resources
│   └── pubspec.yaml                    # Flutter dependencies
│
├── iot_based_plant_monitoring_system/  # Firmware & Microcontroller Code
│   ├── main/                           # Main Arduino sketch
│   │   ├── config.h                    # Configuration file
│   │   ├── sensors.ino                 # Sensor interface code
│   │   ├── wifi.ino                    # WiFi connectivity
│   │   ├── cloud.ino                   # Cloud communication
│   │   └── main.ino                    # Main program logic
│   ├── utilities/                      # Utility functions
│   ├── calibration/                    # Sensor calibration scripts
│   └── documentation/                  # Technical documentation
│
├── libraries/                          # Arduino Libraries
│   ├── DHT/                            # DHT sensor library
│   ├── ArduinoJson/                    # JSON library
│   ├── WiFi/                           # WiFi communication
│   └── other_libs/                     # Additional libraries
│
├── backend/                            # Cloud Backend (Optional)
│   ├── api/                            # REST API endpoints
│   ├── controllers/                    # Business logic
│   ├── models/                         # Database models
│   ├── middleware/                     # Authentication & validation
│   ├── config/                         # Configuration files
│   ├── package.json                    # Node.js dependencies
│   └── server.js                       # Express server
│
├── web-dashboard/                      # Web Interface (Optional)
│   ├── public/                         # Static files
│   ├── src/                            # React/Vue source code
│   ├── package.json                    # Dependencies
│   └── README.md                       # Dashboard documentation
│
├── Untitled Sketch.fzz                 # Fritzing Circuit Design
├── schematic design 1.png              # Circuit Schematic Image
├── README.md                           # This file
├── LICENSE                             # Project license
├── .gitignore                          # Git ignore file
└── CONTRIBUTING.md                     # Contribution guidelines
```

---

## ⚙️ Configuration

### Microcontroller Configuration (config.h)

```cpp
// WiFi Configuration
#define SSID "Your_WiFi_Name"
#define PASSWORD "Your_WiFi_Password"

// Sensor Pins
#define DHT_PIN 4
#define MOISTURE_PIN A0
#define LIGHT_PIN A1
#define PUMP_PIN 12
#define RELAY_PIN 13

// Calibration Values
#define MOISTURE_DRY 1023
#define MOISTURE_WET 300
#define CALIBRATION_OFFSET 2

// Sampling Interval (milliseconds)
#define SENSOR_READ_INTERVAL 5000
#define CLOUD_SYNC_INTERVAL 30000

// Cloud Configuration
#define FIREBASE_URL "your-firebase-url"
#define FIREBASE_SECRET "your-firebase-key"
#define API_ENDPOINT "https://your-api.com/api"
```

### Cloud Database Structure

```json
{
  "users": {
    "user_id": {
      "email": "user@example.com",
      "password_hash": "hashed_password",
      "profile": {
        "name": "User Name",
        "profile_picture": "url"
      },
      "devices": ["device_id_1", "device_id_2"],
      "created_at": "timestamp"
    }
  },
  "devices": {
    "device_id": {
      "name": "Living Room Plant",
      "device_type": "esp32",
      "firmware_version": "1.0.0",
      "last_sync": "timestamp",
      "status": "online/offline",
      "settings": {
        "sync_interval": 30000,
        "alert_thresholds": {
          "moisture_min": 30,
          "temperature_max": 30
        }
      }
    }
  },
  "sensor_data": {
    "device_id": {
      "timestamp": {
        "temperature": 25.5,
        "humidity": 65,
        "moisture": 45,
        "light": 1200,
        "ph": 6.5
      }
    }
  }
}
```

---

## 🔌 API Documentation

### REST API Endpoints

#### Authentication
```
POST /api/auth/register
POST /api/auth/login
POST /api/auth/logout
POST /api/auth/refresh-token
```

#### Device Management
```
GET    /api/devices                 # Get all devices
POST   /api/devices                 # Create new device
GET    /api/devices/:id             # Get device details
PUT    /api/devices/:id             # Update device
DELETE /api/devices/:id             # Delete device
```

#### Sensor Data
```
GET    /api/data/:device_id         # Get latest sensor data
GET    /api/data/:device_id/history # Get historical data
POST   /api/data/:device_id         # Post sensor reading
GET    /api/data/:device_id/export  # Export data as CSV
```

#### Alerts & Notifications
```
GET    /api/alerts                  # Get all alerts
POST   /api/alerts                  # Create new alert
PUT    /api/alerts/:id              # Update alert
DELETE /api/alerts/:id              # Delete alert
```

#### Plants & Care
```
GET    /api/plants                  # Get plant database
GET    /api/plants/:id              # Get plant care info
POST   /api/care-schedule           # Set care schedule
GET    /api/recommendations/:device_id  # Get care recommendations
```

### Example API Calls

#### Login
```bash
curl -X POST http://api.example.com/api/auth/login \
  -H "Content-Type: application/json" \
  -d '{"email":"user@example.com","password":"password123"}'
```

#### Get Device Data
```bash
curl -X GET http://api.example.com/api/data/device123 \
  -H "Authorization: Bearer your_token_here"
```

#### Post Sensor Reading
```bash
curl -X POST http://api.example.com/api/data/device123 \
  -H "Content-Type: application/json" \
  -H "Authorization: Bearer your_token" \
  -d '{
    "temperature": 25.5,
    "humidity": 65,
    "moisture": 45,
    "light": 1200
  }'
```

---

## 🐛 Troubleshooting

### Common Issues & Solutions

#### Device Not Connecting to WiFi

**Problem**: Device LED not turning solid blue
```
Solution:
1. Check WiFi SSID and password in config.h
2. Verify WiFi router is within range
3. Restart the device
4. Check if WiFi frequency is 2.4GHz (not 5GHz)
5. Reset WiFi by holding reset button for 10 seconds
```

#### No Sensor Readings

**Problem**: Sensor values showing 0 or -1
```
Solution:
1. Check sensor wiring connections
2. Verify correct pins in config.h
3. Run calibration sketch
4. Test sensor with simple Arduino sketch
5. Check sensor power supply (usually 5V)
6. Ensure sensors are properly seated on breadboard
```

#### Cloud Sync Not Working

**Problem**: Data not appearing in cloud/dashboard
```
Solution:
1. Verify Firebase URL and API key
2. Check WiFi connection status
3. Verify firewall settings
4. Check cloud sync interval timing
5. Look at serial monitor for error messages
6. Verify database permissions and rules
```

#### Mobile App Not Receiving Alerts

**Problem**: Notifications not arriving on phone
```
Solution:
1. Check notification permissions in app settings
2. Verify alert thresholds are set correctly
3. Restart mobile app
4. Check device connectivity status
5. Verify email/SMS provider configuration
6. Check spam folder for email alerts
```

#### Inaccurate Sensor Readings

**Problem**: Sensor values don't match manual measurements
```
Solution:
1. Calibrate sensors using calibration sketch
2. Check sensor age and expiration
3. Verify sensor is not near heat sources
4. Allow 30-minute warm-up time after startup
5. Ensure sensors are in correct plant location
6. Clean sensor contacts
```

### Serial Monitor Debugging

Enable serial debugging to monitor device operation:

```cpp
Serial.begin(115200);
Serial.println("Device Starting...");
Serial.print("Temperature: "); Serial.println(temperature);
Serial.print("Moisture: "); Serial.println(moisture);
```

View serial output:
- Arduino IDE → Tools → Serial Monitor
- Set baud rate to 115200
- Observe log messages for error codes

---

## 🤝 Contributing

We welcome contributions! Please follow these guidelines:

### How to Contribute

1. **Fork the Repository**
   ```bash
   git clone https://github.com/avrojit-ovi/IoT-Based_Plant_Monitoring_System.git
   cd IoT-Based_Plant_Monitoring_System
   ```

2. **Create Feature Branch**
   ```bash
   git checkout -b feature/your-feature-name
   ```

3. **Make Your Changes**
   - Follow existing code style
   - Add comments for complex logic
   - Test thoroughly
   - Update documentation

4. **Commit Your Changes**
   ```bash
   git commit -am 'Add new feature: description'
   ```

5. **Push to Branch**
   ```bash
   git push origin feature/your-feature-name
   ```

6. **Submit Pull Request**
   - Provide clear description of changes
   - Reference related issues
   - Include test results

### Contribution Areas

- Bug fixes and improvements
- New sensor integration
- Cloud platform enhancement
- Mobile app features
- Documentation improvements
- Translation support
- Hardware optimizations

### Code Style Guidelines

- Use meaningful variable names
- Add comments for complex sections
- Follow Arduino coding conventions
- Keep functions under 50 lines
- Use constants for magic numbers
- Include error handling

---

## 📄 License

This project is licensed under the **MIT License** - see the [LICENSE](LICENSE) file for details.

MIT License allows you to:
- ✅ Use commercially
- ✅ Modify the code
- ✅ Distribute copies
- ✅ Use privately

With the condition that:
- Include original license
- State significant changes
- Include copyright notice

---

## 📞 Contact & Support

### Get Help

- **GitHub Issues**: [Report bugs](https://github.com/avrojit-ovi/IoT-Based_Plant_Monitoring_System/issues)
- **Discussions**: [Ask questions](https://github.com/avrojit-ovi/IoT-Based_Plant_Monitoring_System/discussions)
- **Documentation**: Check [Wiki](https://github.com/avrojit-ovi/IoT-Based_Plant_Monitoring_System/wiki)

### Connect with Developer

- **GitHub**: [@avrojit-ovi](https://github.com/avrojit-ovi)
- **Email**: [your-email@example.com]
- **LinkedIn**: [Your LinkedIn Profile]
- **Twitter**: [@your-twitter-handle]

### Community

- Join our Discord server for community support
- Participate in project discussions
- Share your project setups and configurations
- Help other users troubleshoot issues

---

## 🚀 Future Roadmap

- [ ] Advanced machine learning for plant health prediction
- [ ] Mobile app for iOS and Android native development
- [ ] Integration with smart home systems (Alexa, Google Home)
- [ ] Multiple language support
- [ ] Community plant care database
- [ ] Computer vision for plant disease detection
- [ ] Blockchain-based data verification
- [ ] Enhanced data analytics dashboard
- [ ] Integration with weather APIs
- [ ] Solar power management system

---

## 📚 Additional Resources

- [Arduino Documentation](https://docs.arduino.cc/)
- [ESP32 Documentation](https://docs.espressif.com/projects/esp-idf/en/latest/esp32/)
- [Firebase Guide](https://firebase.google.com/docs)
- [IoT Best Practices](https://iot.mozilla.org/docs/getting-started/index.html)
- [Plant Care Guide](https://www.plantsnap.com/)

---

## 🙏 Acknowledgments

- Sensor library developers
- Arduino and ESP community
- Firebase for cloud services
- All contributors and supporters

---

<div align="center">

**Made with ❤️ for plant lovers and IoT enthusiasts**

[⬆ Back to top](#iot-based-plant-monitoring-system)

</div>
