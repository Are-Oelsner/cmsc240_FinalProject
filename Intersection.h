//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 	

#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Lane.h"
#include "Section.h"

//******************************************************************************
//* TODO
class Intersection {

  protected:

    //**************************************************************************
    //* Private Variables

  	//*******
    //* Lanes
    
    Lane north;	//* TODO
    Lane east;	//* TODO
    Lane south;	//* TODO
    Lane west;	//* TODO

	//**************
    //* Intersection

    Section NW;	//* TODO
    Section NE;	//* TODO
    Section SE;	//* TODO
    Section SW;	//* TODO

  public:
    
    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    Intersection();

    //* Constructor
    Intersection(int length);

    //* Destructor
    ~Intersection();
};

#endif
