// Name: libLCD.h
// Created by: Bruno DELATTRE
// Date: 12/08/2017
// Description: LCD 16*2 gesture
//
// Version: 1.0.0

#include <LiquidCrystal_I2C.h>
#include "var.h"

LiquidCrystal_I2C lcdi2c(LCD_ADDR, LCD_ROW, LCD_LINE);
byte wifiChar[] = {
  B01110,
  B10001,
  B00100,
  B01010,
  B00000,
  B00100,
  B00000,
  B00000
};
byte mqttChar[] = {
  B10000,
  B10000,
  B10100,
  B10100,
  B10101,
  B10101,
  B10101,
  B00000
};
byte degreChar[] = {
 B00110,
  B01001,
  B01001,
  B00110,
  B00000,
  B00000,
  B00000,
  B00000
};

class libLCD {

private:


public:


	libLCD() {
	}

	~libLCD() {
	}

	//
	// begin
	//
	void begin()
	{
		lcdi2c.begin(LCD_ROW, LCD_LINE);
		lcdi2c.backlight();
		lcdi2c.createChar(0, wifiChar);
		lcdi2c.createChar(1, mqttChar);
		lcdi2c.createChar(2, degreChar);
	}

	void displayText() {
		int x = 0;
		lcdi2c.setCursor(x, 0);
		lcdi2c.print("Temp");
		lcdi2c.setCursor(x, 1);
		lcdi2c.print("Hum");

		lcdi2c.setCursor(9, 0);
		lcdi2c.write(2);
		lcdi2c.setCursor(10, 0);
		lcdi2c.print("C");
		lcdi2c.setCursor(8, 1);
		lcdi2c.print("%");

		//lcdi2c.setCursor(14, 0);
		//lcdi2c.print("W");
		lcdi2c.setCursor(14, 1);
		lcdi2c.print("Db");
	}

	//
	// displayData
	//
	void displayData(float temp, float hum)
	{
		int x = 5;
		lcdi2c.setCursor(x, 0);
		lcdi2c.print(temp, 1);
		lcdi2c.setCursor(x, 1);
		lcdi2c.print(hum, 0);
	}

	//
	// displayWiFi connexion KO
	//
	void displayWiFiKo()
	{
		lcdi2c.setCursor(14, 0);
		lcdi2c.print("!");
	}

	//
	// displayWiFi connexion OK
	//
	void displayWiFiOk()
	{
		lcdi2c.setCursor(14, 0);
		lcdi2c.write(0);
	}

	//
	// displayMQTT connexion KO
	//
	void displayMQTTKo()
	{
		lcdi2c.setCursor(15, 0);
		lcdi2c.print("!");
	}

	//
	// displayMQTT connexion OK
	//
	void displayMQTTOk()
	{
		lcdi2c.setCursor(15, 0);
		lcdi2c.write(1);
	}
	//
	// displayWiFiDbSignal
	//
	void displayWiFiDbSignal(String signal)
	{
		lcdi2c.setCursor(11, 1);
		lcdi2c.print(signal);
	}
};



