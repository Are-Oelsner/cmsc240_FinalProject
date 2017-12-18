//* CMSC240 Final Project : Intersection.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#include "Intersection.h"
#include <iostream> //TODO Remove 

Intersection::Intersection() {
  length = 20; //default length

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
  this->length = length;
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

void Intersection:: printIntersection2() {
  north.printLane();
  east.printLane();
  south.printLane();
  west.printLane();
  cout << "***********************************************************************" << endl;
}

void Intersection:: printIntersection() {
  for(int i = 0; i < length; i++) {
    for(int j = 0; j < length; j++) {
      if(j == (length/2)-1)
        south.getSection(i)->printSection();
      else if(j == length/2)
        north.getSection((length-1)-i)->printSection();
      else if(i == (length/2)-1)
        west.getSection((length-1)-j)->printSection();
      else if(i == length/2)
        east.getSection(j)->printSection();
      else
        cout << "   ";
    }
    cout << endl;
  }
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
  TrafficLight nTraffic = north.getTrafficLight();
  TrafficLight eTraffic = east.getTrafficLight();
  TrafficLight sTraffic = south.getTrafficLight();
  TrafficLight wTraffic = west.getTrafficLight();

  double n = nTraffic.timeRemaining(time);
  double e = eTraffic.timeRemaining(time);
  double s = sTraffic.timeRemaining(time);
  double w = wTraffic.timeRemaining(time);

  if(n==0) {nTraffic.change();}
  if(e==0) {eTraffic.change();}
  if(s==0) {sTraffic.change();}
  if(w==0) {wTraffic.change();}


  printIntersection();

  for(int i = 0; i < vehicles.size(); i++) {
    vehicles[i].printVehicle();
    vehicles[i].move();
  }

}
