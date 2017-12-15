//* CMSC240 Final Project : Intersection.h
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:12/14/17

#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Lane.h"
#include "Section.h"

//******************************************************************************
//* Intersection Class owns Lanes and intersection sections. 
class Intersection {

  protected:

    //**************************************************************************
    //* Private Variables

    //*******
    //* Lanes
    Lane north;	
    Lane east;	
    Lane south;	
    Lane west;	

    //**************
    //* Intersection

    Section NW;
    Section NE;
    Section SE;
    Section SW;	

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
