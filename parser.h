#ifndef __parser_h__
#define __parser_h__
#include <string>

using namespace std;


class parser
{
protected:
	double left_probability;
	double right_probability;


	double g_ticks;
	double y_ticks;
	double r_ticks;


	double car_prob;
	double SUV_prob;
	double truck_prob;

	int section_num;


public:
	void parseConfigFile(string file);



};

#endif
