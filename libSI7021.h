// Name: libSD.h
// Created by: Bruno DELATTRE
// Date: 13/09/2017
// Description: micro SD card reader gesture
//
// Version: 1.0.0


#include <SI7021.h>

class libSI7021 {

private:
	SI7021 sensor;
public:

	libSI7021() {
	}

	~libSI7021() {
	}

	//
	// init
	//
	void init() {
		sensor.begin();
	}

	//
	// getTemperature
	//
	float getTemperature() {
		float temp = sensor.getCelsiusHundredths();
		return temp / 100;
	}

	//
	// getHumidity
	//
	float getHumidity() {
		return sensor.getHumidityPercent();
	}
};



