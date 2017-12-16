//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __SECTION_H__
#define __SECTION_H__
#include <cstdlib> 
using namespace std;

//******************************************************************************
//* TODO
class Section {

  private:

    //**************************************************************************
    /// Private Variables

    //* Neighbors
    Section* up;        //* Up neighbor
    Section* right;     //* Right neighbor
    Section* down;      //* Down neighbor
    Section* left;      //* Left neighbor

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
    //* Traffic Flow TODO we might not need these

    //* TODO
    //* @return     bool 
    inline bool getNorth() { return up != NULL; } 

    //* TODO
    //* @return     bool
    inline bool getEast() { return right != NULL;  }

    //* TODO
    //* @return     bool
    inline bool getSouth() { return down != NULL; }

    //* TODO
    //* @return     bool
    inline bool getWest() { return left != NULL;  }

    //**************************************************************************
    //* Neighbors

    //* TODO
    //* @return     TODO
    inline Section* getUpSection() { return up; }

    //* TODO
    //* @return     TODO
    inline Section* getRightSection() { return right; }

    //* TODO
    //* @return     TODO
    inline Section* getDownSection() { return down; }

    //* TODO
    //* @return     TODO
    inline Section* getLeftSection() { return left; }

    //**************************************************************************
    //* Other

    //* TODO
    //* @return     TODO
    inline bool getOccupied() { return occupied; }

    //* TODO
    //* @return     TODO
    inline bool getNearIntersection() { return nearIntersection; }

    //* TODO
    //* @return     TODO
    inline bool getInIntersection() { return inIntersection; }

    //* TODO
    //* @return     TODO
    inline bool getNearEdge() { return nearEdge; }

    //**************************************************************************
    //* Set Functions

    //**************************************************************************
    //* Neighbors
    //* TODO
    //* @param  _section   TODO
    //* @param  direction   TODO                            
    void setNeighbor(Section* _section, int direction);

    //**************************************************************************
    //* Other

    //* TODO
    //* @param  _occupied   TODO
    inline void setOccupied(bool _occupied) { occupied = _occupied; }

    //* Sets whether the section is near the edge of the lane
    //* @param  _nearEdge  TODO
    inline void setNearEdge(bool _nearEdge) { nearEdge = _nearEdge; }

    //* Sets whether section is a section directly connected to an 
    //* intersection section
    //* @param  _nearIntersection  true if near the intersection, false if not
    inline void setNearIntersection(bool _nearIntersection) { nearIntersection = _nearIntersection; }

    //* Sets whether section is in the intersection
    //* @param  _nearIntersection  true if the section is in the intersection, false if not
    inline void setInIntersection(bool _inIntersection) { inIntersection = _inIntersection; }

};

#endif
