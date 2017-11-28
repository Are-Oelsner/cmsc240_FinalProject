#include <TrafficLight.h> 
#include <iostream>
using namespace std;


void TrafficLight::change(Color newColor)
{
	currentColor = newColor;
}

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

void TrafficLight::setGreenTime(int time)
{
	greenTime = time;
}

void TrafficLight::setRedTime(int time)
{
	redTime = time;
}
void TrafficLight::setYellowTime(int time)
{
	yellowTime = time;
}

Color TrafficLight::getColor()
{
	return currentColor;
}

int TrafficLight::timeRemaining(Color color, int timeElapsed)
{
	if(color === green) 
	{
		return greenTime-timeElapsed;
	}
	if(color === yellow)
	{
		return yellowTime - timeElapsed;
	}
	return 0;
}