#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD"; 

#define IR_SENSOR_PIN 15  // IR Sensor Output Pin

WebServer server(80);  

void handleRoot() {
  int sensorState = digitalRead(IR_SENSOR_PIN);  
  String status = (sensorState == LOW) ? "Object Detected" : "No Object";  

  String webpage = "<html><head>";
  webpage += "<meta http-equiv='refresh' content='2'>"; // Auto-refresh every 2 seconds
  webpage += "<title>ESP32 Object Detection</title></head><body>";
  webpage += "<h1>ESP32 Object Detection</h1>";
  webpage += "<h2>Status: " + status + "</h2>";
  webpage += "</body></html>";

  server.send(200, "text/html", webpage);
}

void setup() {
  Serial.begin(115200);
  pinMode(IR_SENSOR_PIN, INPUT);

  WiFi.mode(WIFI_STA);  // Ensure ESP32 is in station mode
  WiFi.begin(ssid, password);

  Serial.print("Connecting to WiFi...");
  int attempts = 0;
  while (WiFi.status() != WL_CONNECTED) { 
    delay(500);
    Serial.print(".");
    attempts++;
  }

  if (WiFi.status() == WL_CONNECTED) {
    Serial.println("\nConnected to WiFi!");
    Serial.println(WiFi.localIP());
    server.on("/", handleRoot);
    server.begin();
    Serial.println("HTTP Server started!");
  } else {
    Serial.println("\nWiFi Connection Failed! Restarting ESP32...");
    delay(3000);
    ESP.restart(); 
  }
}


void loop() {
  server.handleClient();
}
