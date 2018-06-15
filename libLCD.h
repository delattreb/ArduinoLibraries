// Name: libLCD.h
// Created by: Bruno DELATTRE
// Date: 12/08/2017
// Description: LCD 16*2 gesture
//
// Version: 1.0.0

#include <LiquidCrystal_I2C.h>
#include "var.h"

LiquidCrystal_I2C lcdi2c(LCD_ADDR, LCD_ROW, LCD_LINE);

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
	}

	void displayText() {
		int x = 0;
		lcdi2c.setCursor(x, 0);
		lcdi2c.print("Temp");
		lcdi2c.setCursor(x, 1);
		lcdi2c.print("Hum");

		lcdi2c.setCursor(10, 0);
		lcdi2c.print("C");
		lcdi2c.setCursor(8, 1);
		lcdi2c.print("%");

		lcdi2c.setCursor(14, 0);
		lcdi2c.print("W");
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
	// displayWiFi connexion
	//
	void displayWiFiConnexion(String connexion)
	{
		lcdi2c.setCursor(15, 0);
		lcdi2c.print(connexion);
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



