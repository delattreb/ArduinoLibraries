//
// Created by Bruno on 12/08/2017.
//

#include <SimpleDHT.h>

SimpleDHT22 dht22;


class libDHT22 {

private:


public:

	libDHT22() {
	}

	~libDHT22() {
	}

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



