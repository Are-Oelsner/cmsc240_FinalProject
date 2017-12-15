//* CMSC240 Final Project : Parser.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:   

#ifndef __PARSER_H__
#define __PARSER_H__

#include <string>
#include <vector>

using namespace std;


class Parser {

protected:

	double left_prob;
	double right_prob;
    

	double g_ticks;
	double y_ticks;
	double r_ticks;


	double car_prob;
    double SUV_prob;
	double truck_prob;

    int section_num;
    vector<string> info1;
public:


	void parseConfigFile(string filename); 
    
    //get methods for the variables

    double getLeft_Prob();
    
    double getRight_Prob();
    
    double getStraight_Prob();
    

    double getG_Ticks();

    double getY_Ticks();

    double getR_Ticks();
    
    double getCar_Prob();

    double getSUV_Prob();

    double getTruck_Prob();

    int getSection_Num();

};

#endif
