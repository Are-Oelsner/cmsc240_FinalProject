//* CMSC240 Final Project : TrafficLight.cpp 
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/15/2017

#include "TrafficLight.h"

	TrafficLight::TrafficLight() {
		greenTime = 5;
		redTime = 5;
		yellowTime = 3;
		currentColor = green;
  }

	TrafficLight::~TrafficLight() {}
	//contructor
	TrafficLight::TrafficLight(double greenT, double redT, double yellowT, 
		Color startColor) {
		greenTime = greenT;
		redTime = redT;
		yellowTime = yellowT;
		currentColor = startColor;
	}


	void TrafficLight::change() {
		if(currentColor == red){
			currentColor=green;
		}
		else if(currentColor==yellow)
		{
			currentColor=red;
		}
		else 
		{
			currentColor=yellow;
		}

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
			timeE = greenTime-timeElapsed;

		}
		else if(currentColor == yellow)
		{
			timeE = yellowTime - timeElapsed;
		}
		else
		{
			timeE =  redTime-timeElapsed;
		}
		return timeE;
	}
