//
// Created by Bruno on 30/06/2017.
//

#include "RTClib.h"

class libRTC{

private:
	DS1307 rtc;

public:

	libRTC() {
	}

	~libRTC() {
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

	DateTime getDateTime() {
		DateTime now = rtc.now();
		return now;
	}

	String getDateTimeStr()
	{
		DateTime now = rtc.now();
		return String(now.day()) + "/" + String(now.month()) + "/" + String(now.year()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
	}

	String getDateTimeStrEn()
	{
		DateTime now = rtc.now();
		return String(String(now.year()) + "-" + String(now.month()) + "-" + now.day()) + " " + String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
	}

	String getDateStr()
	{
		DateTime now = rtc.now();
		return String(now.day()) + "/" + String(now.month()) + "/" + String(now.year());
	}

	String getTimeStr() {
		DateTime now = rtc.now();
		return String(now.hour()) + ":" + String(now.minute()) + ":" + String(now.second());
	}
};



