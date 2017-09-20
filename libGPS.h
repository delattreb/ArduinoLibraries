//
// Created by Bruno on 12/08/2017.
//

#include "TinyGPS.h"
#include <SoftwareSerial.h>


TinyGPS tinygps;
SoftwareSerial nss(RXPIN, TXPIN);

class libGPS {

private:

protected:

public:
	libGPS() {
	}

	~libGPS() {
	}

	void begin()
	{
		nss.begin(SERIAL_SOFT);
	}

	//
	// getSpeed
	//
	void getSpeed(float *kmph)
	{
		*kmph = tinygps.f_speed_kmph(); // speed in km/hr
#ifdef INFO
		Serial.print("Vit: ");
		Serial.println(*kmph);
#endif
	}

	//
	// getCourse
	//
	void getCourse(float *fc)
	{
		*fc = tinygps.f_course(); // course in degrees
#ifdef INFO
		Serial.print("Cour: ");
		Serial.println(*fc);
#endif
	}
	
	//
	// getAltitude
	//
	void getAltitude(float *alt)
	{

		*alt = tinygps.f_altitude(); // +/- altitude in meters
#ifdef INFO
		Serial.print("Alt ");
		Serial.println(*alt);
#endif
	}

	//
	// isFix
	//
	int isFix()
	{
		float flat, flon;
		unsigned long fix_age;

		tinygps.f_get_position(&flat, &flon, &fix_age);
		if (fix_age == TinyGPS::GPS_INVALID_AGE)
			return NOK;
		else if (fix_age > 5000)
			return READY;
		else
			return OK;
	}

	//
	// getDateTime
	//
	void getDateTime(unsigned long *date, unsigned long *time, unsigned long *fix_age)
	{
		// time in hhmmsscc, date in ddmmyy
		tinygps.get_datetime(date, time, fix_age);
	}

	//
	// getDateTime
	//
	/*
	void getDateTime(DateTime *now)
	{
		int year;
		byte month, day, hour, minute, second, hundredths;
		unsigned long fix_age;

		tinygps.crack_datetime(&year, &month, &day, &hour, &minute, &second, &hundredths, &fix_age);

		DateTime nowGPS;
		nowGPS.setyear(int(year));
		nowGPS.setmonth(int(month));
		nowGPS.setday(int(day));
		nowGPS.sethour(int(hour));
		nowGPS.setminute(int(minute));
		nowGPS.setsecond(int(second));
		*now = nowGPS;
#ifdef INFO
		Serial.print("Time: ");
		Serial.print(now->hour());
		Serial.print(":");
		Serial.print(now->minute());
		Serial.print(":");
		Serial.print(now->second());
		Serial.print(" Date: ");
		Serial.print(now->day());
		Serial.print("/");
		Serial.print(now->month());
		Serial.print("/");
		Serial.println(now->year());
#endif
	}*/

	//
	// getStatistics
	//
	void getStatistics(unsigned long *chars, unsigned short *sentences, unsigned short *failed_checksum)
	{
		tinygps.stats(chars, sentences, failed_checksum);
#ifdef INFO
		Serial.print("Nb Char: ");
		Serial.println(*chars);
		Serial.print("Phrase ok: ");
		Serial.println(*sentences);
		Serial.print("Checksum: ");
		Serial.println(*failed_checksum);
#endif
	}

	//
	// getPosition
	//
	void getPosition(long *flat, long *flon, unsigned long *fix_age)
	{
		tinygps.get_position(flat, flon, fix_age);
#ifdef INFO
		Serial.print("Lat: ");
		Serial.print(*flat);
		Serial.print(" Lon: ");
		Serial.println(*flon);
#endif 
	}

	//
	// getData
	//
	bool getData()
	{
		bool newdata = false;
		unsigned long start = millis();

		while (millis() - start < ACQ_GPS_DURATION) {
			if (nss.available()) {
				char c = nss.read();
				// Serial.print(c);  
				if (tinygps.encode(c)) {
					newdata = true;
					// break;  // uncomment to print new data immediately!
				}
			}
		}
		return newdata;
	}
};