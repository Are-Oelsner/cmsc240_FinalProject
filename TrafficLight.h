//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __traffic_h__
#define __traffic_h__


class TrafficLight
{
public:
    
    //traffic color enum
    enum Color { red, green, yellow};
    
    //constructor
    TrafficLight(int green, int red, int yellow);
    
    void change(Color newColor);
    
    //getters
    int getGreenTime();
    int getYellowTime();
    int getRedTime();
    
    //get color
    Color getColor();
    
    
    //remaining time
    int timeRemaining(Color color, int timeElapsed);

protected:
	//time
	int greenTime; 
	int yellowTime;
	int redTime;

	//variable to store current state
	Color currentColor;

};

#endif
