//* CMSC240 Final Project : Parser.cpp 
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:  Dec 15, 2017 
//*This class parses the config file  

#include "Parser.h"
#include <algorithm>
#include <iostream>
#include <fstream>
#include <cctype>
#include <sstream>
#include <vector>

using namespace std;


//parses config file and puts result in vector
void Parser::parseConfigFile(string filename)
{


    cout << "Opening config file" << endl;
     ifstream in;
    in.open(filename.c_str());
    if(in.bad()){
      cerr<< "Cannot open input file";
        exit(1);
    }
    string line;
    

    vector<string> info;
    while(getline(in, line)){
      if(line[0] != '#' && line[0] != '\0'){
              stringstream info(line);
      string segment;
      vector<string> seglist;
      while(getline(info, segment, '=')){
          seglist.push_back(segment);
      }
      //left probability at index 0
      if(seglist[0].compare("left_probability")==1){

          info1.push_back(seglist[1]);
      } 
      //index 1
      else if(seglist[0].compare("right_probability")==1){
           info1.push_back(seglist[1]);
      } 
      //index 2
      else if(seglist[0].compare("g_ticks")==1){
          info1.push_back(seglist[1]);
      } 
      //index 3
      else if(seglist[0].compare("y_ticks")==1){
           info1.push_back(seglist[1]);
      }
      //index 4
      else if(seglist[0].compare("r_ticks")==1){
           info1.push_back(seglist[1]);
      }
      //index 5
      else if(seglist[0].compare("car_prob")==1){
          info1.push_back(seglist[1]);
      }
      //index 6
      else if(seglist[0].compare("SUV_prob")==1){
          info1.push_back(seglist[1]);
      }
      //index 7
      else if(seglist[0].compare("section_num")==1){
           info1.push_back(seglist[1]);
      }
          
      }
    }
}


//GETTERS
double Parser::getLeft_Prob()
{
  return atof(info1[0].c_str());
}

double Parser::getRight_Prob()
{
	 return atof(info1[1].c_str());
}

double Parser::getStraight_Prob()
{
  return 1-atof(info1[1].c_str())-atof(info1[0].c_str());
}
    
double Parser::getG_Ticks()
{
	 return atof(info1[2].c_str());
}

double Parser::getY_Ticks()
{
	 return atof(info1[3].c_str());
}	

double Parser::getR_Ticks()
{
	 return atof(info1[4].c_str());
}
    
double Parser::getCar_Prob()
{	
	 return atof(info1[5].c_str());
}

double Parser::getSUV_Prob()
{
	 return atof(info1[6].c_str());
}

double Parser::getTruck_Prob()
{
	 return 1.0 - atof(info1[6].c_str())-atof(info1[5].c_str());
}

int Parser::getSection_Num()
{
	 return atof(info1[7].c_str());
}


	