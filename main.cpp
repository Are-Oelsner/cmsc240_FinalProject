//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#include "Parser.h"
#include "TrafficLight.h"
#include "Clock.h"
#include "Intersection.h"
#include "Vehicle.h"
#include "Random.h"
#include "Statistics.h"

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

  int* vehicleType = new int[4]; // Array of the next vehicle type for each lane
  vehicleType[0] = 0;
  vehicleType[1] = 0;
  vehicleType[2] = 0;
  vehicleType[3] = 0;
  vehicleType[4] = 0;



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
	int totalSUV = 0;
	int totalTruck = 0;
	int totalVehicles = 0;
  // *** Add endTime to parser file?
  // *** Add frequency of vehicle spawn to parser file?

	double endTime = 10.0;
	double duration;
	clock_t start;
	int seconds = 0;

	start = clock();
	duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
	while ( duration < endTime ) {

		for(int i = 1; i <= 4; i++) {
			//CAR 
      		double type = Random::randDouble(0.0,1.0);
      		Lane* lane = trafficIntersection->getLane(i);

			if(type <= carProb) { 
				
				if(vehicleType[i] < 1 || vehicleType[i] > 4) {// If Vehicle spawned last timestep roll for new type
				  vehicleType[i] = 2; // Change this to randomly pick based on probabilities TODO
				}
				// If the lane has space for the vehicle this timestep then add it, if
				// not store vehicle type and try again next timestep. 
				if( lane->canAllocSections(vehicleType[i]) ) {  //TODO Error Here TODO
					Vehicle newVehicle = Vehicle(vehicleType[i], rightProb, leftProb, lane);
				    //for stats
				    totalVehicles++;
				    totalCars++;

				    trafficIntersection->addVehicle(newVehicle);
				    vehicleType[i] = 0; // resets vehicle type after it spawns. 
				}
			}
			//SUV
      		else if(type <= carProb + SUVProb) { 
				
				if(vehicleType[i] < 1 || vehicleType[i] > 4) {// If Vehicle spawned last timestep roll for new type
				  vehicleType[i] = 3; // Change this to randomly pick based on probabilities TODO
				}
				// If the lane has space for the vehicle this timestep then add it, if
				// not store vehicle type and try again next timestep. 
				if(lane->canAllocSections(vehicleType[i])) {  //TODO Error Here TODO
				  Vehicle newVehicle = Vehicle(vehicleType[i], rightProb, leftProb, lane);
				  //for stats
				  totalVehicles++;
				  totalSUV++;


				  trafficIntersection->addVehicle(newVehicle);
				  vehicleType[i] = 0; // resets vehicle type after it spawns. 
				}
			}
			//Truck
			else { 
				
				if(vehicleType[i] < 1 || vehicleType[i] > 4) {// If Vehicle spawned last timestep roll for new type
				  vehicleType[i] = 4; // Change this to randomly pick based on probabilities TODO
				}
				// If the lane has space for the vehicle this timestep then add it, if
				// not store vehicle type and try again next timestep. 
				if(lane->canAllocSections(vehicleType[i])) {  //TODO Error Here TODO
				  Vehicle newVehicle = Vehicle(vehicleType[i], rightProb, leftProb, lane);
				  //for stats
				  totalVehicles++;
				  totalTruck++; 


				  trafficIntersection->addVehicle(newVehicle);
				  vehicleType[i] = 0; // resets vehicle type after it spawns. 
				}
			}
			
			trafficIntersection->update();

		   	while (duration < seconds + 1) {
		      duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
		    }
		    seconds++;
    	}

	}

  	std::vector<double> v;
	Statistics* stats = new Statistics(totalCars, totalSUV, totalTruck, totalVehicles, 0,0,0, v,v,v);	
	stats->printStatistics();




  //	************************* OLD TESTER **************************
  /*
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

  Vehicle newVehicle = Vehicle(carProb, SUVProb, truckProb, rightProb, leftProb, trafficIntersection->getEastLane(), spawnSections);

  cout << endl;

  trafficIntersection->printIntersection();

  // for each vehicle : vehicle[i].move()
  newVehicle.move();

  trafficIntersection->printIntersection();

  for(int i = 0; i < 7; i++) {
  newVehicle.move();

  trafficIntersection->printIntersection();

  cout << "*******************************************" << endl;
  }
  */

  return 0;
}
