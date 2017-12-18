//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __TRAFFIC_H__
#define __TRAFFIC_H__

#include <iostream>

using namespace std;

//******************************************************************************
//* TODO - Class description
class TrafficLight {

public:

	//**************************************************************************
    //* Public Variables
    double timeE;
    //* Traffic color enum
    enum Color { red, green, yellow };
    
    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    TrafficLight();

    //* Constructor
    TrafficLight(double green, double red, double yellow, Color startColor);

    //* Destructor
    ~TrafficLight();

    //**************************************************************************
    //* Functions
    
    //* Changes the current color of the TrafficLight
    //* @param 	newColor 	Color to change the TrafficLight to
    void change();
    
    //**************************************************************************
    //* Get Functions

    //* Returns the time duration of a green light
    //* @return integer time duration of a green light
    double getGreenTime();

    //* Returns the time duration of a yellow light
    //* @return integer time duration of a yellow light
    double getYellowTime();

    //* Returns the time duration of a red light
    //* @return integer time duration of a red light
    double getRedTime();
    
    //* Returns the current color of the TrafficLight
    //* @return  Color 	current color of the TrafficLight
    Color getColor();
    
    //* Remaining time duration of the current color
    double timeRemaining(double timeRemaining);

    protected:

	//**************************************************************************
    //* Private Variables

	Color currentColor;	//* Current color of the TrafficLight

	//* Times
	double greenTime; 	//* Time duration of a green light
	double yellowTime;	//* Time duration of a yellow light
	double redTime;	//* Time duration of a red light

};

#endif
