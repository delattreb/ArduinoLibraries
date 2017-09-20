//
// Created by Bruno on 13/09/2017.
// v1.0.0
//

#include <SI7021.h>

class libSI7021 {

private:
	SI7021 sensor;
public:

	libSI7021() {
	}

	~libSI7021() {
	}

	void init() {
		sensor.begin();
	}

	float getTemperature() {
		float temp = sensor.getCelsiusHundredths();
		return temp / 100;
	}

	float getHumidity() {
		return sensor.getHumidityPercent();
	}
};



