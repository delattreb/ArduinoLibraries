// Name: lib18B20.h
// Created by: Bruno DELATTRE
// Date: 12/08/2017
// Description: DS18B20 Dallas tempterature/humidity sensor 
//
// Version: 1.0.0

#include <OneWire.h>
#include <DallasTemperature.h>

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);
DeviceAddress insideThermometer;

class lib18b20 {

private:
	
protected:

public:
	
	lib18b20() {
	}

	~lib18b20() {
	}

	//
	// begin
	//
	void begin()
	{
		sensors.begin();
		// set the resolution to 9-12 bit 
		sensors.setResolution(insideThermometer, 10);
		sensors.getAddress(insideThermometer, 0);
#ifdef INFO
		Serial.println("DS18B20 OK");
		
		Serial.print(sensors.getDeviceCount(), DEC);
		Serial.println(" device");

		// report parasite power requirements
		Serial.print("Parasite power is: ");
		if (sensors.isParasitePowerMode()) Serial.println("ON");
		else Serial.println("OFF");
	
		if (!sensors.getAddress(insideThermometer, 0)) Serial.println("Unable to find address");

		// show the addresses we found on the bus
		Serial.print("Address: ");
		printAddress(insideThermometer);
		Serial.println();

		Serial.print("Resolution: ");
		Serial.println(sensors.getResolution(insideThermometer), DEC);
		Serial.println("");
#endif 
	}

	//
	// getData
	//
	void getData(float *temp)
	{
		sensors.requestTemperatures();
		*temp = sensors.getTempC(insideThermometer);
#ifdef INFO
		Serial.print("Temp: ");
		Serial.print(*temp);
#endif 

	}
	//
	// printAddress
	//
	void printAddress(DeviceAddress deviceAddress)
	{
		for (uint8_t i = 0; i < 8; i++)
		{
			if (deviceAddress[i] < 16) Serial.print("0");
			Serial.print(deviceAddress[i], HEX);
		}
	}
};




