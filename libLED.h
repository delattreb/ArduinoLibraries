// Name: libLED.h
// Created by: Bruno DELATTRE
// Date: 17/08/2017
// Description: LED
//
// Version: 1.0.0

class libLED {

private:

public:

	libLED() {
	}

	~libLED() {
	}
	
	//
	// BlinkLed
	//
	void BlinkLed(int cpt, int time) {
		for (int i = 1; i <= cpt; i++)
		{
			digitalWrite(LED_PIN, HIGH);
			delay(time);
			digitalWrite(LED_PIN, LOW);
			delay(time);
		}
	}
};
