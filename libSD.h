// Name: libSD.h
// Created by: Bruno DELATTRE
// Date: 30/06/2017
// Description: micro SD card reader gesture
//
// Version: 1.0.0

#include <SD.h>


class libSD {

private:

public:

	libSD() {
	}

	~libSD() {
	}

	//
	// init
	//
	void init() {
		if (!SD.begin(SD_CS_PIN)) {
#ifdef INFO
			Serial.println("SD not connected");
#endif 
		}
		else {
#ifdef INFO
			Serial.println("SD connected");
#endif 
		}
	}

	//
	// WriteDataTemp
	//
	void WriteDataTemp(float temp, float hum, String now, String file) {
		if (!SD.begin(SD_CS_PIN)) {}
		File myFile = SD.open(file, FILE_WRITE);
		if (myFile) {
#ifdef DEBUG
			Serial.println("Write data");
#endif 
			// Write data
			myFile.print(now);
			myFile.print(";");

			myFile.print(temp);
			myFile.print(";");
			myFile.print(hum);
			myFile.println(";");

			myFile.close();
		}
		else {
#ifdef DEBUG
			Serial.println("SD KO");
#endif 
		}
	}

	//
	// WriteData
	//
	void WriteData(long lat, long lon, float gpsaltitude, float gpscourse, float speed, int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz, float dstemp, float temp, float hum, float pres, String now, String file) {
		if (!SD.begin(SD_CS_PIN)) {}
		File myFile = SD.open(file, FILE_WRITE);
		if (myFile) {
			//Date
			myFile.print(now);
			myFile.print(";");

#ifdef ARDUINO_1
			//GPS
			myFile.print(lat);
			myFile.print(";");
			myFile.print(lon);
			myFile.print(";");
			myFile.print(String(gpsaltitude));
			myFile.print(";");
			myFile.print(String(gpscourse));
			myFile.print(";");
			myFile.print(String(speed));
			myFile.print(";");

			//DS18B20
			myFile.print(String(dstemp));
			myFile.print(";");

			//SI7021
			myFile.print(String(temp));
			myFile.print(";");
			myFile.println(String(hum));
#endif

#ifdef ARDUINO_2
			//BME280
			myFile.print(String(pres));
			myFile.print(";");
			
			//Gyro
			myFile.print(ax);
			myFile.print(";");
			myFile.print(ay);
			myFile.print(";");
			myFile.print(az);
			myFile.print(";");
			myFile.print(gx);
			myFile.print(";");
			myFile.print(gy);
			myFile.print(";");
			myFile.println(gz);
#endif

			myFile.close();
		}
		else {
#ifdef DEBUG
			Serial.println("SD KO");
#endif
		}
	}
};



