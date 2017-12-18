//* CMSC240 Final Project : TrafficLight.cpp 
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/15

#include "TrafficLight.h"

	TrafficLight::TrafficLight() {
		greenTime = 5;
		redTime = 5;
		yellowTime = 3;
		currentColor = green;
  }

	TrafficLight::~TrafficLight() {}
	//contructor
	TrafficLight::TrafficLight(double greenT, double redT, double yellowT) {
		greenTime = greenT;
		redTime = redT;
		yellowTime = yellowT;
		currentColor = green;
	}


	void TrafficLight::change(Color newColor) {
		currentColor = newColor;
	}

	//COLOR GETTERS
	double TrafficLight::getGreenTime() {
		return greenTime;
	}

	double TrafficLight::getYellowTime() {
		return yellowTime;
	}

	double TrafficLight::getRedTime() {
		return redTime;
	}


	//get current color
	TrafficLight::Color TrafficLight::getColor() {
		return currentColor;
	}

	double TrafficLight::timeRemaining(double timeElapsed) {
		if(currentColor == green) 
		{
			return greenTime-timeElapsed;
		}
		if(currentColor == yellow)
		{
			return yellowTime - timeElapsed;
		}
		return 0;
	}
