#include <ESP8266WiFi.h>
#include <DHT.h>
#include <OneWire.h>
#include <DallasTemperature.h>
#include <FirebaseESP8266.h>

// Your WiFi credentials
char ssid[] = "AZIZ WIFI ";
char pass[] = "998987@joy407";

// Firebase credentials
#define FIREBASE_HOST "iot-botanika-default-rtdb.firebaseio.com"
#define FIREBASE_AUTH "AIzaSyAPBDFEI2TLTjjwYE9yGqQAL7zpwwszQhc"

DHT dht(D4, DHT11);

#define ONE_WIRE_BUS D2
OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

#define soil A0

FirebaseData firebaseData; // Create a FirebaseData object

bool onlineStatus = false;
char currentSSID[50];
char currentPass[50];
unsigned long lastDataUploadTime = 0;
const unsigned long dataUploadInterval = 30000; // 30 seconds
unsigned long connectionStartTime = 0;

void setup() {
  Serial.begin(9600);
  delay(100);

  Serial.println("Connecting to Wi-Fi...");
  WiFi.begin(ssid, pass);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWi-Fi connected");

  // Store online status, SSID, and password in global variables
  onlineStatus = true;
  strcpy(currentSSID, ssid);
  strcpy(currentPass, pass);

  dht.begin();
  sensors.begin();

  // Initialize Firebase
  Firebase.begin(FIREBASE_HOST, FIREBASE_AUTH);
  Firebase.reconnectWiFi(true);

  // Set online status as "online" in Firebase
  Firebase.setString(firebaseData, "Data/Other Data/status/OnlineStatus", "online");
  Firebase.setString(firebaseData, "Data/Other Data/WiFi/SSID", currentSSID);
  Firebase.setString(firebaseData, "Data/Other Data/WiFi/Password", currentPass);

  // Record the initial data upload time
  lastDataUploadTime = millis();

  // Record the Firebase connection start time
  connectionStartTime = millis();
}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();

  if (isnan(h) || isnan(t)) {
    Serial.println("Failed to read from DHT sensor!");
  } else {
    Serial.print("DHT Temperature: ");
    Serial.print(t);
    Serial.println(" °C");
    Serial.print("DHT Humidity: ");
    Serial.print(h);
    Serial.println(" %");
    // Upload data to Firebase
    
    Firebase.setString(firebaseData, "Data/Sensors/DHT1/Temperature", String(t));
    Firebase.setString(firebaseData, "Data/Sensors/DHT2/Humidity", String(h));

    // Update the last data upload time
    lastDataUploadTime = millis();
  }

  sensors.requestTemperatures();
  float ds18b20Temp = sensors.getTempCByIndex(0);
  Serial.print("DS18B20 Temperature: ");
  Serial.print(t -3.23);
  Serial.println(" °C");
  // Upload data to Firebase
  Firebase.setString(firebaseData, "Data/Sensors/DS18B20/Temp", String(t -3.23));

  // Update the last data upload time
  lastDataUploadTime = millis();

  int soilMoisture = analogRead(soil);
  soilMoisture = map(soilMoisture, 0, 1024, 0, 100);
  soilMoisture = (soilMoisture - 100) * -1;
  Serial.print("Soil Moisture: ");
  Serial.print(soilMoisture);
  Serial.println(" %");
  Serial.print("-------------");
  Serial.println("   ");
  // Upload data to Firebase
  String soilMoistureWithPercent = String(soilMoisture) + " %";
Firebase.setString(firebaseData, "Data/Sensors/Capacitive Soil Moisture sensor/SoilMoisture", soilMoistureWithPercent);

  // Update the last data upload time
  lastDataUploadTime = millis();

  // Check if it's been more than 30 seconds since the last data upload
  if (millis() - lastDataUploadTime >= dataUploadInterval) {
    // Set online status as "offline" in Firebase
    Firebase.setString(firebaseData, "Data/Other Data/status/OnlineStatus", "offline");
  } else {
    // Update the connection timer if data has been uploaded
    Firebase.setFloat(firebaseData, "Data/Other Data/status/ConnectionTime", (millis() - connectionStartTime) / 1000.0);
  }

  delay(1); // Delay for a moment to reduce serial monitor output frequency
}
