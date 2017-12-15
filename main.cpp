//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

//main class
#include "Parser.h"
#include "TrafficLight.h"
#include <iostream>

//create instance variables 
Parser p;


int main(int argc, const char * argv[])
{
	//parse congfig file 
	p.parseConfigFile("simulation.config");
	//store values in public variables 
	double lefProb = p.getLeft_Prob();
	double rightProb = p.getRight_Prob();
	double straiProb = p.getStraight_Prob();
	double g = p.getG_Ticks();
	double r = p.getR_Ticks();
	double y = p.getY_Ticks();
	double carProb = p.getCar_Prob();
	double truckProb = p.getTruck_Prob();
	double SUVProb = p.getSUV_Prob();
	double sectNum = p.getSection_Num();


	//set up traffic light 
	//b/c color is enum 
	//0=red, 1=green, 3=yellow
	TrafficLight light = TrafficLight((int)g, (int)r, (int)y);
	light.change(TrafficLight::red);
	cout << light.getColor() << endl;

	return 0;
}
