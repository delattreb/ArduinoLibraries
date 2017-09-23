// Name: libSD.h
// Created by: Bruno DELATTRE
// Date: 30/06/2017
// Description: micro SD card reader gesture
//
// Version: 1.0.0

#include <SD.h>

class libSD {

private:
	String log_file;
	int sdpin;

public:

	libSD() {
	}

	~libSD() {
	}

	//
	// init
	//
	void init(int sd_pin, String logfile) {
		log_file = logfile;
		sdpin = sd_pin;
		
		if (!SD.begin(sdpin)) {
#ifdef INFO
			Serial.println("SD KO!");
#endif 
		}
		else {
#ifdef INFO
			Serial.println("SD OK");
#endif 
		}
	}

	//
	// WriteDataTemp
	//
	void WriteDataTemp(float temp, float hum, String now) {
		if (!SD.begin(sdpin)) {}
		File myFile = SD.open(log_file, FILE_WRITE);
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
	void WriteData(long lat, long lon, float gpsaltitude, float gpscourse, float speed, int16_t ax, int16_t ay, int16_t az, int16_t gx, int16_t gy, int16_t gz, float dstemp, float temp, float hum, float pres, String now) {
		if (!SD.begin(sdpin)) {}
		File myFile = SD.open(log_file, FILE_WRITE);
		if (myFile) {
			//Date
			myFile.print(now);
			myFile.print(";");

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
			myFile.print(gz);
			myFile.print(";");

			//DS18B20
			myFile.print(String(dstemp));
			myFile.print(";");

			//BME280
			myFile.print(String(temp));
			myFile.print(";");
			myFile.print(String(hum));
			myFile.print(";");
			myFile.println(String(pres));
			myFile.close();
		}
		else {
		}
	}
};



