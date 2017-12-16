//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#include "Clock.h"

Clock::Clock()
{
	time = 0;
}

Clock::~Clock() {}


double Clock::getTime()
{
	return time;
}

double Clock::incrementTime()
{
	time++;
	return time;
}


