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
Statistics::Statistics() {} 


//constructor 
Statistics::Statistics(int cars, int SUV, int truck, int totalVehicles, int left, int right, 
int straight, vector<double> leftTime, vector<double> rightTime, vector<double> straightTime)
{
	vehicleLeft = left;
    vehicleRight=right;
    vehicleStraight=straight;
    totalCar = cars;
    totalSUV = SUV;
    totalTruck = truck;
    totalVehicle = totalVehicles;
    leftTime = this->leftTime;
    rightTime = this->rightTime;
    straightTime = this->straightTime;

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
