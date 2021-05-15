#include "VaseSensors.h"
#include "Config.h"
#include <Arduino.h>
#include <DHT.h>
#include <Adafruit_Sensor.h>

VaseSensors::VaseSensors() {
    light = humidity = temp = (float)0;
    moisture = 0;
}

void VaseSensors::begin(DHT dht) {
    pinMode(PIN_DHT, INPUT);
    pinMode(LDR_PIN, INPUT);
    pinMode(PIN_SOIL, INPUT);

    dht.begin();

    light = humidity = temp = (float)0;
    moisture = 0;
}

void VaseSensors::makeMeasurements(DHT dht) {
    setLight();
    setDHT(dht);
    setSoilMoisture();
}

void VaseSensors::setLight() {
    int   ldrRawData;
    float resistorVoltage, ldrVoltage;
    float ldrResistance;
    float ldrLux;

    ldrRawData = analogRead(LDR_PIN);
  
  // Convert the raw digital data back to the voltage that was measured on the analog pin
  resistorVoltage = (float)ldrRawData / MAX_ADC_READING * ADC_REF_VOLTAGE;

  // voltage across the LDR is the 5V supply minus the 5k resistor voltage
  ldrVoltage = ADC_REF_VOLTAGE - resistorVoltage;
  
  // LDR_RESISTANCE_CONVERSION
  // resistance that the LDR would have for that voltage  
  ldrResistance = ldrVoltage/resistorVoltage * REF_RESISTANCE;
  
  // LDR_LUX
  // Change the code below to the proper conversion from ldrResistance to
  // ldrLux
  ldrLux = LUX_CALC_SCALAR * pow(ldrResistance, LUX_CALC_EXPONENT);

  light = ldrLux;
}

void VaseSensors::setDHT(DHT dht) {
  humidity = dht.readHumidity();
  temp = dht.readTemperature();

  if(isnan(humidity) || isnan(temp)) {
    Serial.println("Failed to read from DHT");
    humidity = temp = (float)0;
  }
}

void VaseSensors::setSoilMoisture() {
  moisture = analogRead(PIN_SOIL);
}

float VaseSensors::getHumidity() {
  return humidity;
}

float VaseSensors::getLight() {
  return light;
}

int VaseSensors::getMoisture() {
  return moisture;
}

float VaseSensors::getTemperature() {
  return temp;
}