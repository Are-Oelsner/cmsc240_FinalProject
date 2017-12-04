#include "parser.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
using namespace std;

void parser::parseConfigFile(string filename)
{
	cout << "Parsing" << endl;
	ifstream file(filename);
    string line;
    while( getline( file, line ) )   
    {
       	std::istringstream iss( line );
        string result;
        if( std::getline( iss, result , '=') )
        {
            if(result.compare("left_probability"))
            {
            	std::string token;
            	if(std::getline( iss, token, ';' ) )
                {
                    left_prob = atof(token.c_str());
                }
         
            }
            
            else if(result.compare("right_probability"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {
                	cout << token << endl;
               		right_prob = atof(token.c_str());
               	}
            }

            else if(result.compare("g_ticks"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {
                	 std::cout << token << std::endl;
               		g_ticks = atof(token.c_str());
               	}
            }
               

            else if(result.compare("y_ticks"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {

               		y_ticks = atof(token.c_str()); 
               	}
            }

            else if(result.compare("r_ticks"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {
               		r_ticks = atof(token.c_str());
               	}
            }
            else if(result.compare("car_prob"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {
               		car_prob = atof(token.c_str());
               	}
            }
            else if(result.compare("SUV_prob"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {
               		SUV_prob = atof(token.c_str());
               	}
            }
            else if(result.compare("section_num"))
            {
 				std::string token;
 				if(std::getline( iss, token, ';' ) )
                {
               		section_num = atof(token.c_str());
               	}
            }
                
              
   	 	}
	}
}



double parser::getLeft_Prob()
{
	return left_prob;
}

double parser::getRight_Prob()
{
	return right_prob;
}
    
double parser::getG_Ticks()
{
	return g_ticks;
}

double parser::getY_Ticks()
{
	return y_ticks;
}	

double parser::getR_Ticks()
{
	return r_ticks;
}
    
double parser::getCar_Prob()
{	
	return car_prob;
}

double parser::getSUV_Prob()
{
	return SUV_prob;
}

double parser::getTruck_Prob()
{
	return truck_prob;
}

int parser::getSection_Num()
{
	return section_num;
}


	