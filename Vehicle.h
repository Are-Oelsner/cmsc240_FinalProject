//* CMSC240 Final Project : Vehicle.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 	

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Section.h"
#include "Lane.h"
#include "TrafficLight.h"

using namespace std;

//******************************************************************************
//* This class includes the data and functions of a Vehicle.
class Vehicle {

  protected:

    int size;				//* Integer size of the Vehicle
    bool inIntersection;	//* True if the Vehicle is in an intersection
    bool nearIntersection;	//* True if the front of the Vehicle is in the 
    						//* section immediately before the intersection
    
    char path;				//* The path that the Vehicle will ultimately take 
    						//* based on the probabilities to go right, left, or
    						//* straight ('s'/straight, 'r'/right, 'l'/left)

    vector<Section*> sections;	//* Sections that the Vehicle occupies
    Section* frontSection;      //* Section that contains the front of the Vehicle
    Section* backSection; 	    //* Section that contians the back of the Vehicle
    Lane* currLane; 		    //* Lane that the Vehicle is currently in

    double probRight; 
    double probLeft;
    double probStraight;

  public:

    //**************************************************************************
    //* Constructors & Destructors

    //* Constructor
    Vehicle(string _type, double _probRight, double _probLeft, Lane* _lane, vector<Section*> _sections);

    //* Destructor
    ~Vehicle();

    //**************************************************************************
    //* Functions

    //* Decides what path the Vehicle will ultimately take based on the given
    //* probabilities that it will turn right, left, or continue straight.
    //* @param  probRight   double probability that the Vehicle will turn right
    //* @param 	probLeft 	double probability that the Vehicle will turn left
    void decidePath(double _probRight, double _probLeft);

    //* Returns whether the vehicle can move in the given direction
    //* @param  	direction 	char direction to check availability for the 
    //* 						Vehicle to move ('s', 'r', 'l')
    //* @return 	true if the vehicle can move in the desired direction
    bool canMove(char _direction);

    //* Moves the vehicle one unit forward, right, or left
    void move();

};

#endif
