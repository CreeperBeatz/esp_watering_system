#include <Arduino.h>
#include <WiFi.h>
#include <HTTPClient.h>
#include "Config.h"
#include "VaseSensors.h"
#include <DHT.h>
#include <Adafruit_Sensor.h>

// delay between sending data to db
unsigned long lastTime = 0;
unsigned long timerDelay = 360000;

//FIXME bandage fix
DHT dht(PIN_DHT, DHTTYPE);
VaseSensors sensors;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  dht.begin();
  sensors.begin();

  WiFi.begin(ssid, password);
  Serial.println("Connecting");
  while(WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.print("Connected to WiFi network with IP Address: ");
  Serial.println(WiFi.localIP());

}

void loop() {
  // put your main code here, to run repeatedly:
  if((millis()-lastTime) > timerDelay) {

    sensors.makeMeasurements(dht);
    //proceed only if connected
    if(WiFi.status() == WL_CONNECTED) {
      HTTPClient http;

      http.begin(serverName);
      http.addHeader("Content-Type", "application/x-www-form-urlencoded");

      //String tempBandage = apiKey;

      String httpRequestData = "ApiKey=" + String(apiKey) + "&AirTemperature=" + String(sensors.getTemperature()) + "&AirHumidity=" 
                              + String(sensors.getHumidity()) + "&SoilMoisture=" + String(sensors.getMoisture()) + "&Light=" +
                              String(sensors.getLight());

      Serial.print("HTTP Request: ");
      Serial.println(httpRequestData);
      
      int httpResponseCode = http.POST(httpRequestData);

      Serial.print("HTTP Response Code: ");
      Serial.println(httpResponseCode);

      http.end();
    } else {
      Serial.println("WiFi not connected");
    }
    lastTime = millis();
  }
}