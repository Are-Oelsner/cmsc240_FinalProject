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

  // Prints out additional debugging info
  bool debug;
  if(*argv[argc-1] == '1') 
    debug = true;
  else 
    debug = false;

  // Store parser values in public variables 
  //double leftProb = p.getLeftProb();
  //double rightProb = p.getRightProb();
  //double straightProb = p.getStraightProb();

  double leftProb = 0.;
  double rightProb = .99;
  //double straightProb = .01;

  //double g = p.getGTicks();
  //double r = p.getRTicks();
  //double y = p.getYTicks();
  double carProb = p.getCarProb();
  //double truckProb = p.getTruckProb();
  double SUVProb = p.getSUVProb();
  //double sectNum = p.getSectionNum(); // is this the number of secitons/lane?

  int vehicleType[4]; // Array of the next vehicle type for each lane
  vehicleType[0] = 0;
  vehicleType[1] = 0;
  vehicleType[2] = 0;
  vehicleType[3] = 0;
  vehicleType[4] = 0;



  //set up traffic light 
  //b/c color is enum 
  //0=red, 1=green, 3=yellow
  //how to change a light!
  //light.change(TrafficLight::red);

  // Create new intersection 
  Intersection* trafficIntersection = new Intersection();

  // Statistics Object
  Statistics* stats = new Statistics();	

  // Start simulation

  double endTime = 30.0;
  double duration;
  clock_t start;
  int seconds = 0;

  start = clock();
  duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
  while ( duration < endTime ) {

    for(int i = 1; i <= 4; i++) {
      Lane* lane = trafficIntersection->getLane(i);

      if(vehicleType[i] < 1 || vehicleType[i] > 4) { // If vehicle spawned last timestep
        double type = Random::randDouble(0.0,1.0); // determines vehicle type
        if(type <= carProb)  
          vehicleType[i] = 2; 
        else if(type <= carProb + SUVProb) 
          vehicleType[i] = 3; 
        else 
          vehicleType[i] = 4; 
      }
      // If the lane has space for the vehicle this timestep then add it, if
      // not store vehicle type and try again next timestep. 
      if( lane->canAllocSections(vehicleType[i]) ) {  
        Vehicle newVehicle = Vehicle(vehicleType[i], rightProb, leftProb, lane); // Vehicle to be added
        trafficIntersection->addVehicle(newVehicle); // Adds vehicle to intersection
        stats->incrementVehicles(vehicleType[i]); // for statistics
        vehicleType[i] = 0; // resets vehicle type after it spawns. 
      }
    }

    while (duration < seconds + 1) {
      duration = ( clock() - start ) / (double) CLOCKS_PER_SEC;
    }
    seconds++;

    trafficIntersection->update(debug);

  }


  std::vector<double> v; // Temporary vector for leftTime rightTime and straightTime TODO(remove)
  // Outputs Statistics Data after simulation stops
  stats->printStatistics();

  return 0;
}
