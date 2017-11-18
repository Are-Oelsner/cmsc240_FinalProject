/* Vehicle Super Class
 * Children: Car, SUV, Truck
 */
#ifndef __VEHICLE_H__
#define __VEHICLE_H__

#include "Section.h"
#include "Lane.h"

public class Vehicle {
  protected:
    ///Private Variables
    int size;
    bool inIntersection;
    double probLeft;
    double probRight;
    double probLeft;
    Section sections[];

  public:
    ///Constructors
    // Default Constructor
    Vehicle();
    // Copy Constructor
    //TODO
    // Constructor
    Vehicle(int size);

    // Destructor
    ~Vehicle();

    ///Functions
    // move
    void move();
};

#endif
