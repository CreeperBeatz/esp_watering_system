#ifndef CONFIG_H_
#define CONFIG_H_

#include <Arduino.h>

// INTERNET CONNECTION



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