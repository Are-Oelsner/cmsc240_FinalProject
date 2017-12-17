//* CMSC240 Final Project : Intersection.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#include "Intersection.h"

  Intersection::Intersection() {
  	int length = 20; //default length

  	// Creates intersection sections
  	NW = Section();
  	NE = Section();
  	SE = Section();
  	SW = Section();

    // TEMPORARY FIX -- NOT SURE WHAT YOU WANTED TO DO WITH THE TYPES HERE
    Section* NWptr = &NW;
    Section* NEptr = &NE;
    Section* SEptr = &SE;
    Section* SWptr = &SW;

  	// Creates Lanes
  	north = Lane(length, SEptr, NEptr, 1);
  	east = Lane(length, SWptr, SEptr, 2);
  	south = Lane(length, NWptr, SWptr, 3);
  	west = Lane(length, NEptr, NWptr, 4);
  }

  Intersection::Intersection(int length) {
  	// Creates intersection sections
  	NW = Section();
  	NE = Section();
  	SE = Section();
  	SW = Section();

    // TEMPORARY FIX -- NOT SURE WHAT YOU WANTED TO DO WITH THE TYPES HERE
    Section* NWptr = &NW;
    Section* NEptr = &NE;
    Section* SEptr = &SE;
    Section* SWptr = &SW;

  	// Creates Lanes
  	north = Lane(length, SEptr, NEptr, 1);
    east = Lane(length, SWptr, SEptr, 2);
    south = Lane(length, NWptr, SWptr, 3);
    west = Lane(length, NEptr, NWptr, 4);
  }

  //TODO? 
  Intersection::~Intersection() { }

  void Intersection:: printIntersection() {
    north.printLane();
    east.printLane();
    south.printLane();
    west.printLane();
    cout << "****************************************************************************" << endl;
  }

  void Intersection::update() {

    // Handle light timing here? Update trafficlights?

    for(int i = 0; i < vehicles.size(); i++) {
      vehicles[i].move();
    }

    printIntersection();

  }
