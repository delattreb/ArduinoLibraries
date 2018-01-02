// Name: libDHT22.h
// Created by: Bruno DELATTRE
// Date: 12/08/2017
// Description: DHT22 tempterature/humidity sensor 
//
// Version: 1.0.0

#include <SimpleDHT.h>

SimpleDHT22 dht22;


class libDHT22 {

private:


public:

	libDHT22() {
	}

	~libDHT22() {
	}

	//
	// getData
	//
	void getData(float* ttemp, float* thum) {
		float temperature = 0;
		float humidity = 0;
		int err = SimpleDHTErrSuccess;
		if ((err = dht22.read2(PINDHT22, &temperature, &humidity, NULL)) != SimpleDHTErrSuccess) {
			Serial.print("Read DHT22 failed, err="); Serial.println(err); delay(2000);
			return;
		}

		*ttemp = temperature;
		*thum = humidity;
	}
};



