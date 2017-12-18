//* CMSC240 Final Project : Intersection.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Lane.h"
#include "Section.h"
#include "Vehicle.h"
#include "TrafficLight.h"

using namespace std;

//******************************************************************************
//* Intersection Class owns Lanes and intersection sections. 
class Intersection {

  protected:

    //**************************************************************************
    //* Private Variables

    //**************************************************************************
    //* Lanes
    Lane north;	
    Lane east;	
    Lane south;	
    Lane west;	

    //**************************************************************************
    //* Intersection Sections
    Section NW;
    Section NE;
    Section SE;
    Section SW;

    //**************************************************************************
    //* Vehicles
    vector<Vehicle> vehicles;

    //**************************************************************************
    //* TrafficLights
    TrafficLight northTrafficLight;
    TrafficLight eastTrafficLight;
    TrafficLight southTrafficLight;
    TrafficLight westTrafficLight;

    int length;


  public:

    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    Intersection();

    //* Constructor
    Intersection(int length);

    //* Destructor
    ~Intersection();

    //* Functions

    //* Print Intersection
    void printIntersection();
    //* Print + Intersection
    void printIntersection2();

    Lane* getLane(int direction);

    inline Lane* getNorthLane() { return &north; }
    inline Lane* getEastLane() { return &east; }
    inline Lane* getSouthLane() { return &south; }
    inline Lane* getWestLane() { return &west; }

    inline void addVehicle(Vehicle _vehicle) { vehicles.push_back(_vehicle); }

    void update(double time, bool debug);

};

#endif
