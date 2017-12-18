//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/18/2017

#ifndef __SECTION_H__
#define __SECTION_H__

#include <cstdlib>
#include <iostream> 

using namespace std;

//******************************************************************************
//* Section class
class Section {

  private:

    //**************************************************************************
    /// Private Variables

    //* Neighbors
    Section* up;            //* Up neighbor
    Section* right;         //* Right neighbor
    Section* down;          //* Down neighbor
    Section* left;          //* Left neighbor

    bool occupied;          //* Vehicle occupied variable 
    bool nearEdge;          //* If the section is the last in the lane
    bool nearIntersection;  //* If the section is directly connected to an 
                            //* Intersection Section
    bool inIntersection;    //* If the section is in the intersection

  public:

    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    Section();

    //* Destructor
    ~Section();

    //**************************************************************************
    //* Get Functions

    //**************************************************************************
    //* Neighbors

    //* Returns Right Section given orientation
    Section* getRightSection(int direction);

    //* Returns straight Section given orientation
    Section* getStraightSection(int direction);

    //* Returns left Section given orientation
    Section* getLeftSection(int direction);

    //* Returns back Section given orientation
    Section* getBackSection(int direction);


    //**************************************************************************
    //* Traffic Flow

    //* Returns Right section given orientation if possible
    Section* getRight(int direction);

    //* Returns straight section given orientation if possible
    Section* getStraight(int direction);

    //* Returns left section given orientation if possible
    Section* getLeft(int direction);

    //* Returns back section given orientation if possible
    Section* getBack(int direction);


    //**************************************************************************
    //* Neighbors

    //* Returns northern neighbor section
    inline Section* getUpSection() { return up; }

    //* Returns eastern neighbor section
    inline Section* getRightSection() { return right; }

    //* Returns southern neighbor section
    inline Section* getDownSection() { return down; }

    //* Returns western neighbor section
    inline Section* getLeftSection() { return left; }

    //**************************************************************************
    //* Other

    //* Return occupied status bool
    inline bool getOccupied() { return occupied; }

    //* Return near intersection status
    inline bool getNearIntersection() { return nearIntersection; }

    //* Return true if section is in intersection
    inline bool getInIntersection() { return inIntersection; }

    //* Return true if section is the last in its lane
    inline bool getNearEdge() { return nearEdge; }

    //**************************************************************************
    //* Set Functions

    //**************************************************************************
    //* Neighbors
    //* Sets neighbor section based on orientation
    //* @param  _section   
    //* @param  direction  
    void setNeighbor(Section* _section, int direction);

    //**************************************************************************
    //* Other

    //* Sets occupied status
    //* @param  _occupied   bool
    void setOccupied(bool _occupied);

    //* Sets whether the section is near the edge of the lane
    //* @param  _nearEdge  bool
    inline void setNearEdge(bool _nearEdge) { nearEdge = _nearEdge; }

    //* Sets whether section is a section directly connected to an 
    //* intersection section
    //* @param  _nearIntersection  true if near the intersection, false if not
    inline void setNearIntersection(bool nearInt) {nearIntersection = nearInt;}

    //* Sets whether section is in the intersection
    //* @param  _nearIntersection  true if the section is in the intersection
    inline void setInIntersection(bool inInt) {inIntersection = inInt;}

    //* Drawing function used for testing and simulation display
    void printSection();
    //* Original Draw function draws all lanes horizontally
    void printSection2();

    //Debugging

};

#endif
