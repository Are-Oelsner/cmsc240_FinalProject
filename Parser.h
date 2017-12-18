//* CMSC240 Final Project : Parser.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:   

#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;

//******************************************************************************
//* TODO - Class description
class Parser {

  private:

    //**************************************************************************
    //* Functions

    //* Parses information from the file given the filename
    //* @param  string   Name of the file to parse from
    void parseConfigFile(string filename); 

    //**************************************************************************
    //* Private Variables

    double left_prob;      //* Probability that a Vehicle will turn left
    double right_prob;     //* Probability that a Vehicle will turn right
    double straight_prob;


    double g_ticks;        //* Number of ticks for a green light
    double y_ticks;        //* Number of ticks for a yellow light
    double r_ticks;        //* Number of ticks for a red light

    double car_prob;       //* Probability that a Vehicle will spawn as a Car
    double suv_prob;       //* Probability that a Vehicle will spawn as a SUV
    double truck_prob;     //* Probability that a Vehicle will spawn as a Truck

    int section_num;        //* Number of Sections in a Lane
    vector<string> info1;   //* TODO

  public:

    //**************************************************************************
    //* Constructors & Destructors

    Parser(string filename);

    //**************************************************************************
    //* Get Functions

    //* Returns the probability that a Vehicle will turn left
    //* @return     double probability that a Vehicle will turn left
    double getLeftProb();

    //* Returns the probability that a Vehicle will turn left
    //* @return     double probability that a Vehicle will turn left
    double getRightProb();

    //* Returns the probability that a Vehicle will remain straight
    //* @return     double probability that a Vehicle will remain straight
    double getStraightProb();

    //* Returns the number of ticks for a green light
    //* @return     double number of ticks for a green light
    double getGTicks();

    //* Returns the number of ticks for a yellow light
    //* @return     double number of ticks for a yellow light
    double getYTicks();

    //* Returns the number of ticks for a red light
    //* @return     double number of ticks for a red light
    double getRTicks();

    //* Returns the probability that a Vehicle will be spawned as a Car
    //* @return     double probability that a Vehicle will be spawned as a Car
    double getCarProb();

    //* Returns the probability that a Vehicle will be spawned as a SUV
    //* @return     double probability that a Vehicle will be spawned as a SUV
    double getSUVProb();

    //* Returns the probability that a Vehicle will be spawned as a Truck
    //* @return     double probability that a Vehicle will be spawned as a Truck
    double getTruckProb();

    //* Returns the number of Sections in a Lane
    //* @return     integer number of Sections in a Lane
    int getSectionNum();

};

#endif
