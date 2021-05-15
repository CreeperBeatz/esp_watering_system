#ifndef VASE_SENSORS_H_
#define VASE_SENSORS_H_

#include <Arduino.h>
#include <DHT.h>
#include "Config.h"

class VaseSensors
{
    private:
        float light;
        float humidity;
        float temp;
        int moisture;

        //The following methods set the values for:
        //light, humidity, air temp and soil moisture
        //
        //Since some methods require more calculations
        void setLight();
        void setDHT(DHT);
        void setSoilMoisture();

    public:
        VaseSensors();
        void makeMeasurements(DHT);
        void begin(DHT);

        float getLight();
        float getHumidity();
        float getTemperature();
        int getMoisture();
};

#endif