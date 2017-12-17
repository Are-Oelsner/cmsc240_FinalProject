//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#include "Parser.h"
#include "TrafficLight.h"
#include "Clock.h"
#include "Intersection.h"
#include "Vehicle.h"

#include <iostream>
#include <time.h>
#include <string>

using namespace std;

// Create a parser to parse probabilities/timings from external file
Parser p = Parser("simulation.config");
// Create a clock to track simulation time
// Clock c = Clock();
clock_t timer;

int main(int argc, const char * argv[]) {

	// Store parser values in public variables 
	double leftProb = p.getLeftProb();
	double rightProb = p.getRightProb();
	double straightProb = p.getStraightProb();
	double g = p.getGTicks();
	double r = p.getRTicks();
	double y = p.getYTicks();
	double carProb = p.getCarProb();
	double truckProb = p.getTruckProb();
	double SUVProb = p.getSUVProb();
	double sectNum = p.getSectionNum(); // is this the number of secitons/lane?


	//set up traffic light 
	//b/c color is enum 
	//0=red, 1=green, 3=yellow
	TrafficLight light = TrafficLight(g, r, y);
	//how to change a light!
	//light.change(TrafficLight::red);

	// Create new intersection 
	Intersection* trafficIntersection = new Intersection();
	
	// Start simulation
	int carsLeft = 0;
	int carsRight = 0;
	int carStraight = 0;
	int totalCars = 0;

	//while(c.getTime()!= 60){
	//timer = clock();

	//while((float)timer/CLOCKS_PER_SEC <= .10f)
    trafficIntersection->printIntersection();
	//}

	// ***** FIND A BETTER WAY TO ALLOCATE SECTIONS TO A VEHICLE *******
	vector<Section*> spawnSections;
	for(int i = 0; i < 3; i++) {
		spawnSections.push_back(trafficIntersection->getEastLane()->getSection(i));
	}

	Vehicle newVehicle = Vehicle(carProb, SUVProb, truckProb, rightProb, leftProb, straightProb, trafficIntersection->getEastLane(), spawnSections);

	cout << endl;

	trafficIntersection->printIntersection();

	// newVehicle.move();

	return 0;
}
