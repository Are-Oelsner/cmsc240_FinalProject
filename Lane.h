/* CMSC240 Final Project : Lane.h
 * Authors: Are Oelsner, Maddie Shea, Ryan Jennings
 * Date: 12/15/17
 */

#ifndef __LANE_H__
#define __LANE_H__

#include <vector>
#include <cstdlib> 

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

    TrafficLight trafficLight; //* TrafficLight object

  public:

    //**************************************************************************
    //* Constructors & Destructors

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

    //* Returns the section in the lane at the given index
    //* @param i index of the section to return
    //* @return     Section* of the section at index i
    Section* getSection(int i);

    //* Print's Contents of Lane
    //* @return void
    void printLane();

    //* Returns the direction of the lane
    //* @return     integer direction of the lane; 1 = north, 2 = east, 
    //*             3 = south, 4 = west 
    inline int getDirection() { return direction; }

    //* Returns the TrafficLight located in this lane
    //* @return     the TrafficLight in this Lane
    inline TrafficLight getTrafficLight() { return trafficLight; }

    //* Returns a vector<Sections*> of the given number of sections
    //* @param  size    number of sections to allocate
    //* @return     vector<Section*> of sections allocated
    vector<Section*> allocSections(int size);

    //* Returns true if the lane can allocate a given number of sections at the
    //* beginning of the lane and false if it cannot. 
    //* @param  size    number of sections to check if the lane can allocate
    //* @return true if the lane can allocate a given number of sections at the
    //*         beginning of the lane and false if it cannot
    bool canAllocSections(int size);

};

#endif
