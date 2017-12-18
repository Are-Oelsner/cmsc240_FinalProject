/*
Statistics to collect:

- how many cars spawned in the simulation
- how many cars turned left
- how many cars turned right
- how many cars remained straight
- average time for cars to turn left, exit lane
- average time for cars to turn right, exit lane
- average time for cars to remain straight, exit lane
- number of cars spawned
- number of suvs spawned
- number of trucks spawned
- ...

*/
#include "Statistics.h"

//default constructor 
Statistics::Statistics() { 
  vehicleLeft = left;
  vehicleRight=0;
  vehicleStraight=0;

  //Vehicle Stats
  totalCar = 0;
  totalSUV = 0;
  totalTruck = 0;
  totalVehicle = 0;

  //Timing Vectors TODO
  leftTime;
  rightTime;
  straightTime;
}

//print 
void Statistics::printStatistics()
{
	cout << "Printing Statistics" << endl;
	cout << "Number of total vehicles spawned: " << totalVehicle << endl;
	cout << "Number of total  cars spawned: " << totalCar << endl;
	cout << "Number of total SUVs spawned: " << totalSUV << endl;
	cout << "Number of total trucks spawned: " << totalTruck << endl;
	cout << "Number of total vehicles turning left: " << vehicleLeft << endl;
	cout << "Number of total vehicles turning right: " << vehicleRight << endl;
	cout << "Number of total vehicles going straight " << vehicleStraight << endl;
}

void 
Statistics::
incrementVehicles(int size) {
  switch(size) {
    case 2: totalCars++; totalVehicles++; break;
    case 3: totalSUV++; totalVehicles++; break;
    case 4: totalTruck++; totalVehicles++; break;
  }
}

