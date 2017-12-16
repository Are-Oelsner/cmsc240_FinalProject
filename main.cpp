//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

//main class
#include "Parser.h"
#include "TrafficLight.h"
#include <iostream>

using namespace std;

//create instance variables 
Parser p = Parser("simulation.config");


int main(int argc, const char * argv[])
{
	//store values in public variables 
	double lefProb = p.getLeftProb();
	double rightProb = p.getRightProb();
	double straiProb = p.getStraightProb();
	double g = p.getGTicks();
	double r = p.getRTicks();
	double y = p.getYTicks();
	double carProb = p.getCarProb();
	double truckProb = p.getTruckProb();
	double SUVProb = p.getSUVProb();
	double sectNum = p.getSectionNum();


	//set up traffic light 
	//b/c color is enum 
	//0=red, 1=green, 3=yellow
	TrafficLight light = TrafficLight((int)g, (int)r, (int)y);
	//how to change a light!
	light.change(TrafficLight::red);
	

	return 0;
}
