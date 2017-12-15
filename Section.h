//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __SECTION_H__
#define __SECTION_H__

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

    bool occupied;  //* Vehicle occupied variable 

  public:

    //**************************************************************************
    //* Constructors & Destructors

    //* Default Constructor
    Section();

    //* Destructor
    ~Section();

    //**************************************************************************
    //* Get Functions

    //**************
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

    //***********
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

    //**********
    //* Occupied

    //* TODO
    //* @return     TODO
    inline bool getOccupied() { return occupied; }

    //**************************************************************************
    //* Set Functions

    //***********
    //* Neighbors
    //* TODO
    //* @param  _section   TODO
    //* @param  direction   TODO                            
    void setNeighbor(Section* _section, int direction);

    //**********
    //* Occupied
    //* TODO
    //* @param  _occupied   TODO
    inline void setOccupied(bool _occupied) { occupied = _occupied; }

}

#endif
