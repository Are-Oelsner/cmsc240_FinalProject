//* CMSC240 Final Project : TrafficLight.cpp 
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/15/2017

#ifndef __STATISTICS_H__
#define __STATISTICS_H__

#include <vector>
#include <iostream>

using namespace std;

class Statistics {

protected:
    int vehicleLeft;
    int vehicleRight;
    int vehicleStraight;
    int totalCar;
    int totalSUV;
    int totalTruck;
    int totalVehicle;
    vector<double> leftTime;
    vector<double> rightTime;
    vector<double> straightTime;

public:

    //*********************************************************
    //* Constructors
    Statistics();
    
    Statistics(int left, int right, int straight, vector<double> leftTime, vector<double> rightTime, vector<double> straightTime);
    
    //*********************************************************
    //* Methods
    void printStatistics();

    //Increments vehicles based on input size
    void incrementVehicles(int size);

    //Increments Vehicle turn stats
    inline void incrementLeft() {vehicleLeft++;}
    inline void incrementRight() {vehicleRight++;}
    inline void incrementStraight() {vehicleStraight++;}

    //TODO Write function for Timing    
};

#endif