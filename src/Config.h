#ifndef CONFIG_H_
#define CONFIG_H_

#include <Arduino.h>

// INTERNET CONNECTION

const char* ssid = "VIVACOM_NET";
const char* password = "12345678";

String serverName = "192.168.1.7:4000/documents/phptest/esp_data_handler.php";

String apiKey = "r23jo2"; //sync with php file

// DHT CONFIGURATION

#define PIN_DHT                   34
#define DHTTYPE                   DHT22

// LDR CONFIGURATION

#define LDR_PIN                   32
#define MAX_ADC_READING           4095
#define ADC_REF_VOLTAGE           3.3
#define REF_RESISTANCE            3860  // measure this for best results
#define LUX_CALC_SCALAR           12518931
#define LUX_CALC_EXPONENT         -1.405

// SOIL MOISTURE CONFIG

#define PIN_SOIL                  35
//#define AIR_VALUE 620 //when soil humidity sensor is in the air
//#define WATER_VALUE 310 //when soild humidity sensor is completely under water

#endif