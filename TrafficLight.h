//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __traffic_h__
#define __traffic_h__


class TrafficLight
{
protected:
	//traffic color enum
	enum Color { red, green, yellow};

	//time
	int greenTime; 
	int yellowTime;
	int redTime;

	//variable to store current state
	Color currentColor;



public:
	void change(Color to, Color from);

	//getters
	int getGreenTime();
	int getYellowTime();
	int getRedTime();

	//setters 
	void setGreenTime(int time);
	void setRedTime(int time);
	void setYellowTime(int time);
	Color getColor();


	//remaining time
	int timeRemaining(Color color, int timeElapsed);




}

#endif
