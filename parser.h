//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:   

#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>

using namespace std;

//******************************************************************************
//* TODO
class Parser {

protected:

	double left_prob;      //* TODO
	double right_prob;     //* TODO


	double g_ticks;        //* TODO
	double y_ticks;        //* TODO
	double r_ticks;        //* TODO


	double car_prob;       //* TODO
	double SUV_prob;       //* TODO
	double truck_prob;     //* TODO

    int section_num;       //* TODO

public:

    //* TODO
	void parseConfigFile(string filename); 
    
    //get methods for the variables
    //* TODO
    double getLeft_Prob();
    //* TODO
    double getRight_Prob();
    
    //* TODO
    double getG_Ticks();
    //* TODO
    double getY_Ticks();
    //* TODO
    double getR_Ticks();
    
    //* TODO
    double getCar_Prob();
    //* TODO
    double getSUV_Prob();
    //* TODO
    double getTruck_Prob();
    
    //* TODO
    int getSection_Num();

};

#endif
