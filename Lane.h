//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __LANE_H__
#define __LANE_H__

#include <vector>

#include "Vehicle"
#include "Section"

//******************************************************************************
//* TODO
class Lane {

  private:

    //**************************************************************************
    //* Private Variables

    vector<Section*> sections;  //* Vector of Sections in the lane

    int direction;  //* Direction of the traffic flow in the lane; 1 north, 
                    //* 2 east, 3 south, 4 west

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

    //* Changes occupied status     //* ??? what is this

    //* ???
    //* ???
    Section* getSection(int i);

    //* Returns the direction of the lane
    //* @return     integer direction of the lane; 1 = north, 2 = east, 
    //*             3 = south, 4 = west 
    inline int getDirection() { return direction; }

};

#endif
