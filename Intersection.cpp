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

  northTrafficLight = north.getTrafficLight();
  eastTrafficLight = east.getTrafficLight();
  southTrafficLight = south.getTrafficLight();
  westTrafficLight = west.getTrafficLight();

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
  cout << "***********************************************************************" << endl;
}

Lane*
Intersection::
getLane(int direction) {
  switch(direction) {
    case 1: return &north;
    case 2: return &east;
    case 3: return &south;
    case 4: return &west;
  }
}

void Intersection::update(double time) {

  // Handle light timing here? Update trafficlights?
  double n = north.getTrafficLight().timeRemaining(time);
  double e = east.getTrafficLight().timeRemaining(time);
  double s = south.getTrafficLight().timeRemaining(time);
  double w = west.getTrafficLight().timeRemaining(time);

  printIntersection();

  for(int i = 0; i < vehicles.size(); i++) {
    vehicles[i].move();
  }

}
