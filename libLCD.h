// Name: libLCD.h
// Created by: Bruno DELATTRE
// Date: 12/08/2017
// Description: LCD 16*2 gesture
//
// Version: 1.0.0


#include <LiquidCrystal_I2C.h>
#include "var.h"

LiquidCrystal_I2C lcdi2c(LCD_ADDR, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

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
	}

	void displayText() {
		int x = 2;
		lcdi2c.setCursor(x, 0);
		lcdi2c.print("Temp:");
		lcdi2c.setCursor(x, 1);
		lcdi2c.print("Hum:");
		
		x = 13;
		lcdi2c.setCursor(x, 0);
		lcdi2c.print("c");
		lcdi2c.setCursor(x, 1);
		lcdi2c.print("%");
	}
	
	//
	// displayData
	//
	void displayData(float temp, float hum)
	{
		int x = 8;
		lcdi2c.setCursor(x, 0);
		lcdi2c.print(temp, 1);
		lcdi2c.setCursor(x, 1);
		lcdi2c.print(hum, 0);
	}
};



