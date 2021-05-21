#ifndef CONFIG_H_
#define CONFIG_H_

#include <Arduino.h>

// INTERNET CONNECTION

#define ssid "VIVACOM_NET"
#define password "12345678"

#define SERVER_NAME "http://168.192.1.10/ESP/esp_data_handler.php"

#define interval 36000

//sync with php file
#define apiKey "r23jo2" 

// DHT CONFIGURATION

#define PIN_DHT                   25
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