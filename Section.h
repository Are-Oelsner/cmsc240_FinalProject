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
    //* Private Variables

    //* Traffic flow variables
    bool north; //* TODO
    bool east;  //* TODO
    bool south; //* TODO
    bool west;  //* TODO

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

    //* Constructor
    //* @param  n   TODO
    //* @param  e   TODO
    //* @param  s   TODO
    //* @param  w   TODO
    Section(bool n, bool e, bool s, bool w);

    //* Constructor
    //* @param  up      TODO
    //* @param  right   TODO
    //* @param  down    TODO
    //* @param  left    TODO
    Section(Section up, Section right, Section down, Section left);

    //* Constructor
    //* @param  up      TODO
    //* @param  right   TODO
    //* @param  down    TODO
    //* @param  left    TODO
    //* @param  n       TODO
    //* @param  e       TODO
    //* @param  s       TODO
    //* @param  w       TODO
    Section(Section up, Section right, Section down, Section left, bool n, bool e, bool s, bool w);
    
    //* Destructor
    ~Section();

    //**************************************************************************
    //* Get Functions

    //**************
    //* Traffic Flow

    //* TODO
    //* @return     TODO
    inline bool getNorth() { return north; }

    //* TODO
    //* @return     TODO
    inline bool getEast() { return east;  }

    //* TODO
    //* @return     TODO
    inline bool getSouth() { return south; }

    //* TODO
    //* @return     TODO
    inline bool getWest() { return west;  }

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

    //* TODO
    //* @param  n   TODO
    //* @param  i   TODO                                // !!! IMPROVE PARAM NAMES !!!
    void setFlow(bool n, int i);

    //inline void setNorth(bool n) {north = n;}
    //inline void setEast(bool e) {east = e;}
    //inline void setSouth(bool s) {south = s;}
    //inline void setWest(bool w) {west = w;}

    //***********
    //* Neighbors

    //* TODO
    //* @param  _section   TODO
    //* @param  _i   TODO                               // !!! IMPROVE PARAM NAME !!!
    void setNeighbor(Section* _section, int _i);

    //inline void setRight(Section* s) {right = s;}
    //inline void setDown(Section* s) {down = s;}
    //inline void setLeft(Section* s) {left = s;}

    //**********
    //* Occupied

    //* TODO
    //* @param  _occupied   TODO
    inline void setOccupied(bool _occupied) { occupied = _occupied; }

}

#endif
