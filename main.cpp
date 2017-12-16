//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

//main class
#include "Parser.h"
#include "TrafficLight.h"
#include "Clock.h"
#include <iostream>

using namespace std;

//create instance variables 
Parser p = Parser("simulation.config");
Clock c; //create clock

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

	//create clock 
	
	c.incrementTime();
	cout << c.getTime() << endl;



	//set up traffic light 
	//b/c color is enum 
	//0=red, 1=green, 3=yellow
	TrafficLight light = TrafficLight(g, r, y);
	//how to change a light!
	//light.change(TrafficLight::red);
	
	//start simulation
	int carsLeft = 0;
	int carsRight =0;
	int carStraight = 0;
	int totalCars = 0;
	while(c.getTime()!=60)
	{

	}

	return 0;
}
