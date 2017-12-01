#ifndef __INTERSECTION_H__
#define __INTERSECTION_H__

#include "Lane.h"
#include "Section.h"

public class Intersection {
  protected:
    ///Private Variables
    // Lanes
    Lane north;
    Lane east;
    Lane south;
    Lane west;

    // Intersection
    Section NW;
    Section NE;
    Section SE;
    Section SW;

  public:
    ///Constructors
    // Default Constructor
    Intersection();

    // Constructor
    Intersection(int length);

    // Destructor
    ~Intersection();
};

#endif
