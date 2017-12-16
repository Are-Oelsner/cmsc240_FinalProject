//* CMSC240 Final Project : Parser.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:   

#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>

using namespace std;

//******************************************************************************
//* TODO - Class description
class Parser {

protected:

    //**************************************************************************
    //* Private Variables

	double left_prob;      //* Probability that a Vehicle will turn left
	double right_prob;     //* Probability that a Vehicle will turn right
    

	double g_ticks;        //* Number of ticks for a green light
	double y_ticks;        //* Number of ticks for a yellow light
	double r_ticks;        //* Number of ticks for a red light

	double car_prob;       //* Probability that a Vehicle will spawn as a Car
    double SUV_prob;       //* Probability that a Vehicle will spawn as a SUV
	double truck_prob;     //* Probability that a Vehicle will spawn as a Truck

    int section_num;        //* Number of Sections in a Lane
    vector<string> info1;   //* TODO

public:

    //**************************************************************************
    //* Functions

    //* Parses information from the file given the filename
    //* @param  string   Name of the file to parse from
	void parseConfigFile(string filename); 
    

    //**************************************************************************
    //* Get Functions

    //* Returns the probability that a Vehicle will turn left
    //* @return     double probability that a Vehicle will turn left
    double getLeft_Prob();
    
    //* Returns the probability that a Vehicle will turn left
    //* @return     double probability that a Vehicle will turn left
    double getRight_Prob();
    
    //* Returns the probability that a Vehicle will remain straight
    //* @return     double probability that a Vehicle will remain straight
    double getStraight_Prob();
    
    //* Returns the number of ticks for a green light
    //* @return     double number of ticks for a green light
    double getG_Ticks();

    //* Returns the number of ticks for a yellow light
    //* @return     double number of ticks for a yellow light
    double getY_Ticks();

    //* Returns the number of ticks for a red light
    //* @return     double number of ticks for a red light
    double getR_Ticks();
    
    //* Returns the probability that a Vehicle will be spawned as a Car
    //* @return     double probability that a Vehicle will be spawned as a Car
    double getCar_Prob();

    //* Returns the probability that a Vehicle will be spawned as a SUV
    //* @return     double probability that a Vehicle will be spawned as a SUV
    double getSUV_Prob();

    //* Returns the probability that a Vehicle will be spawned as a Truck
    //* @return     double probability that a Vehicle will be spawned as a Truck
    double getTruck_Prob();

    //* Returns the number of Sections in a Lane
    //* @return     integer number of Sections in a Lane
    int getSection_Num();

};

#endif
