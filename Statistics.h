//
//  Statistics.h
//  
//
//  Created by Maddie Shea on 12/17/17.
//

#ifndef Statistics_h
#define Statistics_h
#include <vector>
#include <iostream>

using namespace std;
class Statistics

{
protected:
    int vehicleLeft;
    int vehicleRight;
    int vehicleStraight;
    int totalCar;
    int totalSUV;
    int totalTruck;
    int totalVehicles;
    vector<double> leftTime;
    vector<double> rightTime;
    vector<double> straightTime;

public:
    //*********************************************************
    //Constructors
    Statistics();
    
    Statistics(int cars, int SUV, int truck, int totalVehicles, int left, int right, int straight, vector<double> leftTime, vector<double> rightTime, vector<double> straightTime);
    

    
    //*********************************************************
    //Methods
    void printStatistics();
    
    
    
    
};

#endif /* Statistics_h */
