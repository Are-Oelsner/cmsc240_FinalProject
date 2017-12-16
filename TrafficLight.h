//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __TRAFFIC_H__
#define __TRAFFIC_H__

//******************************************************************************
//* TODO - Class description
class TrafficLight {

protected:

	//**************************************************************************
    //* Private Variables

	Color currentColor;	//* Current color of the TrafficLight

	//* Times
	int greenTime; 	//* Time duration of a green light
	int yellowTime;	//* Time duration of a yellow light
	int redTime;	//* Time duration of a red light

public:

	//**************************************************************************
    //* Public Variables
    
    //* Traffic color enum
    enum Color { red, green, yellow };
    
    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    TrafficLight();

    //* Constructor
    TrafficLight(int green, int red, int yellow);

    //* Destructor
    ~TrafficLight();

    //**************************************************************************
    //* Functions
    
    //* Changes the current color of the TrafficLight
    //* @param 	newColor 	Color to change the TrafficLight to
    void change(Color newColor);
    
    //**************************************************************************
    //* Get Functions

    //* Returns the time duration of a green light
    //* @return integer time duration of a green light
    int getGreenTime();

    //* Returns the time duration of a yellow light
    //* @return integer time duration of a yellow light
    int getYellowTime();

    //* Returns the time duration of a red light
    //* @return integer time duration of a red light
    int getRedTime();
    
    //* Returns the current color of the TrafficLight
    //* @return  Color 	current color of the TrafficLight
    Color getColor();
    
    //* Remaining time duration of the current color
    int timeRemaining(int timeElapsed);

};

#endif
