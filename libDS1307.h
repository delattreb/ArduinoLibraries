// Name: libMPU6050.h
// Created by: Bruno DELATTRE
// Date: 12/08/2017
// Description: DS1307 Real Time clock
//
// Version: 1.0.0

#include "RTClib.h"

class libDS1307{

private:
	DS1307 rtc;

public:

	libDS1307() {
	}

	~libDS1307() {
	}

	void init() {
		rtc.begin();
		if (!rtc.isrunning()) {
#ifdef INFO
			Serial.print("RTC KO ");
#endif 
			rtc.adjust(DateTime(__DATE__, __TIME__));
#ifdef INFO
			Serial.print("adjusted ");
			Serial.println(getDateTimeStr());
#endif 
		}
		else {
#ifdef INFO
			Serial.print("RTC OK ");
			Serial.println(getDateTimeStr());
#endif 
		}
	}

	//
	// adjust
	//
	void adjust()
	{
		rtc.adjust(DateTime(__DATE__, __TIME__));
#ifdef INFO
		Serial.print("Heure: ");
		Serial.println(__TIME__);
		Serial.print("Date: ");
		Serial.println(__DATE__);
#endif
	}

	//
	// getDateTime
	//
	DateTime getDateTime() {
		DateTime now = rtc.now();
		return now;
	}

	//
	// getDateTimeStr
	//
	String getDateTimeStr()
	{
		DateTime now = rtc.now();
		return String(now.day()) + "/" + String(now.month()) + "/" + String(now.year()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
	}

	//
	// getDateTimeStrEn
	//
	String getDateTimeStrEn()
	{
		DateTime now = rtc.now();
		return String(String(now.year()) + "-" + String(now.month()) + "-" + now.day()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
	}

	//
	// getDateStr
	//
	String getDateStr()
	{
		DateTime now = rtc.now();
		return String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
	}

	//
	// getTimeStr
	//
	String getTimeStr() {
		DateTime now = rtc.now();
		return String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
	}
};



