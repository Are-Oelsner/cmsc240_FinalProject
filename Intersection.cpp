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




void Intersection::update(bool debug) {

  counter0++;
  counter1++;
 cout << northTrafficLight.getColor() << endl;

  double n = northTrafficLight.timeRemaining(counter1);
  double e = eastTrafficLight.timeRemaining(counter0);
  double s = southTrafficLight.timeRemaining(counter1);
  double w =westTrafficLight.timeRemaining(counter0);

  if(n==0) {
    northTrafficLight.change(); 
    counter1=0;
  }
  if(e==0) {
    eastTrafficLight.change();
    counter0 = 0;
  }
  if(s==0) {
    southTrafficLight.change();
    counter1 = 0;
  }
  if(w==0) {
    westTrafficLight.change();
    counter0=0;
  }

  for(int i = 0; i < vehicles.size(); i++) {
    vehicles[i].move();
    if(debug)  {
      cout << "Printing Vehicle: " << i << "---------------" << endl;
      vehicles[i].printVehicle();
    }
  }
  printIntersection();
}
