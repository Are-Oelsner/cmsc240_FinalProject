//* CMSC240 Final Project : Lane.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#include "Lane.h"
#include <iostream>

Lane::Lane() {
}

Lane::Lane(int length, Section* intSec1, Section* intSec2, int direction) {
  //if NS, then start red
  if(direction==1 || direction==3)
  {
     trafficLight = TrafficLight(5.0, 5.0, 3.0, TrafficLight::green);

  }
  //if WE, start green
  else
  {
    trafficLight = TrafficLight(5.0, 5.0, 3.0, TrafficLight::red);
  }


  if(length % 2 != 0 || length < 12) {
    cout << "Error: length: " << length << " must be even and at least 12" << endl;
    exit(0);
  }

  int opposite = (direction+2) % 4; // opposite direction
  if(opposite == 0) {
    opposite = 4;
  }

  sections.push_back(new Section()); // first section in lane

  // Add and connect sections before intersection
  for(int i = 1; i < (length/2) - 1; i++) { 
    sections.push_back(new Section());

    sections[i-1]->setNeighbor(sections[i], direction); // set next neighbor
    sections[i]->setNeighbor(sections[i-1], opposite); // set previous neighbor
  }

  // Add intersection sections, set them to be flagged inIntersection
  intSec1->setInIntersection(true);
  intSec2->setInIntersection(true);
  sections.push_back(intSec1);
  sections.push_back(intSec2);

  // Connect last added section to intSec1 and vice-versa
  sections[(length/2) - 2]->setNeighbor(sections[length/2 - 1], direction);
  sections[length/2 - 1]->setNeighbor(sections[(length/2) - 2], opposite);

  // Connect intSec1 to intSec2 and vice-versa
  sections[(length/2) - 1]->setNeighbor(sections[length/2], direction);
  sections[length/2]->setNeighbor(sections[(length/2) - 1], opposite);

  // Add and connect sections after intersection
  for(int i = (length/2) + 1; i < length; i++) { 
    sections.push_back(new Section());

    sections[i - 1]->setNeighbor(sections[i], direction); // sets next neighbor
    sections[i]->setNeighbor(sections[i - 1], opposite); // sets previous neighbor TODO error here as well works first loop then crashes second
  }

  this->direction = direction;

  // Set section before intersection to be flagged nearIntersection
  sections[(length/2) - 2]->setNearIntersection(true);
  // Set section before end of lane to be flagged nearEdge
  sections[length - 1]->setNearEdge(true);

}

Lane::~Lane(){}

Section* Lane::getSection(int i) {
  return sections[i];
}

void Lane::printLane() {
  for(Section* sec : sections) {
    sec->printSection();
  }
  cout << endl;
}

bool Lane::canAllocSections(int size) {

  if(size > 4 || size < 1) {
    cout << "Invalid size: " << size << endl;
    exit(0); 
  }

  else {
    for(int i = 0; i < size; i++) {
      if(getSection(i)->getOccupied() ) {
        return false;
      }
    }
  }

  return true;
}

vector<Section*> Lane::allocSections(int size) {

  if(size > 4 || size < 1) {
    cout << "Invalid size: " << size << endl;
    exit(0); 
  }
  
  // Sections allocated
  vector<Section*> sections;

  if( canAllocSections(size) ) {
    for( int i = 0; i < size; i++ ) {
      sections.push_back(getSection(i));
    }
  }

  return sections;
}
