//* CMSC240 Final Project : Lane.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __LANE_H__
#define __LANE_H__

#include <vector>
#include <cstdlib> 

//#include "Vehicle.h"
#include "Section.h"
#include "TrafficLight.h"

using namespace std;

//******************************************************************************
//* Lane class contains a vector of Section* and an int specifying the direction. 
class Lane {

  private:

    //**************************************************************************
    //* Private Variables

    vector<Section*> sections;  //* Vector of Sections in the lane

    int direction;  //* Direction of the traffic flow in the lane; 1 north, 
                    //* 2 east, 3 south, 4 west

    TrafficLight trafficLight;

  public:

    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    Lane();

    //* Constructor
    //* @param  length      number of sections in the lane
    //* @param  intSec1     first intersection section in the lane
    //* @param  intSec2     second intersection section in the lane
    //* @param  direction   traffic flow direction of the lane; 1 = north, 
    //*                     2 = east, 3 = south, 4 = west 
    Lane(int length, Section* intSec1, Section* intSec2, int direction);

    //* Destructor
    ~Lane();

    //**************************************************************************
    //* Functions

    //* ???
    //* ???
    Section* getSection(int i);

    //* Returns the direction of the lane
    //* @return     integer direction of the lane; 1 = north, 2 = east, 
    //*             3 = south, 4 = west 
    inline int getDirection() { return direction; }

    inline TrafficLight getTrafficLight() { return trafficLight; }

};

#endif
