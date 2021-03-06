// Name: libDS3231.h
// Created by: Bruno DELATTRE
// Date: 11/09/2017
// Description: DS3231 Real Time Clock
//
// Version: 1.0.0

//#include <RtcDS3231.h>
#include "Libraries/DS3231/src/RtcDS3231.h"

RtcDS3231<TwoWire> Rtc(Wire);

class libDS3231 {

private:

public:

	libDS3231() {
	}

	~libDS3231() {
	}

	//
	// init
	//
	static void init(boolean binit) {
		Rtc.Begin();
		RtcDateTime compiled = RtcDateTime(__DATE__, __TIME__);

		if (binit)
		{
#ifdef INFO
			Serial.println("RTC forced");
#endif 
			Rtc.SetDateTime(compiled);
		}

		if (!Rtc.IsDateTimeValid())
		{
#ifdef INFO
			Serial.println("RTC lost");
#endif 
			Rtc.SetDateTime(compiled);
		}

		if (!Rtc.GetIsRunning())
		{
#ifdef INFO
			Serial.println("RTC Run now");
#endif 
			Rtc.SetIsRunning(true);
		}

		RtcDateTime now = Rtc.GetDateTime();
		if (now < compiled)
		{
#ifdef INFO
			Serial.println("Update RTC");
#endif 
			Rtc.SetDateTime(compiled);
		}
		Rtc.Enable32kHzPin(false);
		Rtc.SetSquareWavePin(DS3231SquareWavePin_ModeNone);
	}

	RtcDateTime getDateTime() {
		RtcDateTime now = Rtc.GetDateTime();
		return now;
	}

	//
	// getDateTimeStr
	//
	String setDateTimeStr(String strtime)
	{
		char *time = (char *)malloc(sizeof(char) * strtime.length());
		strcpy(time, strtime.c_str());
		RtcDateTime newtime = RtcDateTime(__DATE__, time);
		Rtc.SetDateTime(newtime);
		free(time);
	}

	//
	// getDateTimeStr
	//
	String getDateTimeStr()
	{
		RtcDateTime now = Rtc.GetDateTime();
		return String(now.Day()) + "/" + String(now.Month()) + "/" + String(now.Year()) + " " + String(now.Hour()) + ":" + String(now.Minute()) + ":" + String(now.Second());
	}

	//
	// getDateTimeStrEn
	//
	String getDateTimeStrEn()
	{
		RtcDateTime now = Rtc.GetDateTime();
		return String(String(now.Year()) + "-" + String(now.Month()) + "-" + now.Day()) + " " + String(now.Hour()) + ":" + String(now.Minute()) + ":" + String(now.Second());
	}

	//
	// getDateStr
	//
	String getDateStr()
	{
		RtcDateTime now = Rtc.GetDateTime();
		return String(now.Day()) + "/" + String(now.Month()) + "/" + String(now.Year());
	}

	//
	// getTimeStr
	//
	String getTimeStr() {
		RtcDateTime now = Rtc.GetDateTime();
		return String(now.Hour()) + ":" + String(now.Minute()) + ":" + String(now.Second());
	}

	//
	// getTemperature
	//
	float getTemperature() {
		RtcTemperature temp = Rtc.GetTemperature();
		return temp.AsFloat();
	}
};




