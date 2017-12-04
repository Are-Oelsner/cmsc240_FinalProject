
//main class
#include "parser.h"
#include <iostream>

parser p;

int main(int argc, const char * argv[])
{
	p.parseConfigFile("simulation.config");
	double n = p.getLeft_Prob();
	//cout << n << endl;
	double y = p.getY_Ticks();
	//cout << y << endl;


	return 0;
}