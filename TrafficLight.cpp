//* CMSC240 Final Project : TrafficLight.cpp 
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/15

#include "TrafficLight.h"
#include <iostream>
using namespace std;

//change the color 
TrafficLight::TrafficLight(int greenT, int redT, int yellowT)
{
	greenTime = greenT;
	redTime = redT;
	yellowTime = yellowT;
	currentColor = green;
}


void TrafficLight::change(Color newColor)
{
	currentColor = newColor;
}

//COLOR GETTERS
int TrafficLight::getGreenTime()
{
	return greenTime;
}

int TrafficLight::getYellowTime()
{
	return yellowTime;
}

int TrafficLight::getRedTime()
{
	return redTime;
}


//get current color
TrafficLight::Color TrafficLight::getColor()
{
	return currentColor;
}

int TrafficLight::timeRemaining(Color color, int timeElapsed)
{
	if(color == green) 
	{
		return greenTime-timeElapsed;
	}
	if(color == yellow)
	{
		return yellowTime - timeElapsed;
	}
	return 0;
}