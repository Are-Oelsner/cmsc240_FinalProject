//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#include "Clock.h"

using namespace std;

double Clock::getTime()
{
	return time;
}

double Clock::incrementTime(double time)
{
	time++;
	return time;
}


