//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#ifndef __SECTION_H__
#define __SECTION_H__

class Section {
  private:
    ///Private Variables
    //Traffic flow variables 
    bool north;
    bool east;
    bool south;
    bool west;

    //neighbors
    Section* up;
    Section* right;
    Section* down;
    Section* left;

    //Vehicle occupied variable 
    bool occupied;

  public:
    ///Constructors
    //Default Constructor
    Section();
    //Constructor
    Section(bool n, bool e, bool s, bool w);
    Section(Section up, Section right, Section down, Section left);
    Section(Section up, Section right, Section down, Section left, bool n, bool e, bool s, bool w);
    
    //Destructor
    ~Section();

    ///Getters
    //Traffic Flow
    inline bool getNorth() {return north;}
    inline bool getEast() {return east;}
    inline bool getSouth() {return south;}
    inline bool getWest() {return west;}

    //Neighbors
    inline Section* getUp() {return up;}
    inline Section* getRight() {return right;}
    inline Section* getDown() {return down;}
    inline Section* getLeft() {return left;}

    //Occupied
    inline bool getOccupied() {return occupied;}

    ///Setters
    //Set Flow
    void setFlow(bool n, int i);
  //inline void setNorth(bool n) {north = n;}
  //inline void setEast(bool e) {east = e;}
  //inline void setSouth(bool s) {south = s;}
  //inline void setWest(bool w) {west = w;}

    //Neighbors 
    void setNeighbor(Section* s, int i);
  //inline void setRight(Section* s) {right = s;}
  //inline void setDown(Section* s) {down = s;}
  //inline void setLeft(Section* s) {left = s;}

    //Occupied
    inline void setOccupied(bool o) {occupied = o;}

}

#endif
