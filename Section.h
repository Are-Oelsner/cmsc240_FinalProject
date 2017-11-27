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
    inline setNorth(bool n) {north = n;}
    inline setEast(bool e) {east = e;}
    inline setSouth(bool s) {south = s;}
    inline setWest(bool w) {west = w;}

    //Neighbors 
    inline setUp(Section* s) {up = s;}
    inline setRight(Section* s) {right = s;}
    inline setDown(Section* s) {down = s;}
    inline setLeft(Section* s) {left = s;}

    //Occupied
    inline setOccupied(bool o) {occupied = o;}

}

#endif
