//* CMSC240 Final Project : Vehicle.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 	

#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Section.h"
#include "Lane.h"
#include "Random.h"

#include <iostream>

using namespace std;

//******************************************************************************
//* This class includes the data and functions of a Vehicle.
class Vehicle {

  protected:

    bool inIntersection;	//* True if the Vehicle is in an intersection
    bool nearIntersection;	//* True if the front of the Vehicle is in the 
    						//* section immediately before the intersection
    bool hasPassedLight;    //* True if the Vehicle has passed into the 
                            //* intersection and no longer needs to check the
                            //* TrafficLight; False otherwise

    vector<Section*> sections;	//* Sections that the Vehicle occupies
    Section* frontSection;      //* Section that contains the front of the Vehicle
    Section* backSection; 	    //* Section that contians the back of the Vehicle
    Lane* frontCurrLane; 		//* Lane that the front of the Vehicle is 
                                //* currently in
    Lane* backCurrLane;         //* Lane that the back of the Vehicle is 
                                //* currently in

    char path;      //* The path that the Vehicle will ultimately take 
                    //* based on the probabilities to go right, left, or
                    //* straight ('s'/straight, 'r'/right, 'l'/left)

    int size;   //* Integer size of the Vehicle, indicates what type of Vehicle
                //* it is; (2/Car, 3/SUV, 4/Truck)

  public:

    //**************************************************************************
    //* Constructors & Destructors

    //* Constructor
    Vehicle(int size, double _rightProb, double _leftProb, Lane* _lane);

    //* Destructor
    ~Vehicle();

    //**************************************************************************
    //* Functions

    //* Decides what path the Vehicle will ultimately take based on the given
    //* probabilities that it will turn right, left, or continue straight.
    //* @param  _probRight   double probability that the Vehicle will turn right
    //* @param 	_probLeft 	double probability that the Vehicle will turn left
    void decidePath(double _rightProb, double _leftProb);

    //* Returns whether the vehicle can move in the given direction
    //* @param  	direction 	char direction to check availability for the 
    //* 						Vehicle to move ('s', 'r', 'l')
    //* @return 	true if the vehicle can move in the desired direction
    bool canMove(char _direction);

    //* Moves the vehicle one unit forward, right, or left
    void move();

};

#endif
