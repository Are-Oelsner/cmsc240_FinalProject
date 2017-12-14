//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#include "Lane.h"

  Lane::Lane() {

  }

  Lane::Lane(int length, Section* intSec1, Section* intSec2, int direction) {
    if(length % 2 != 0) {
      cout << "Error: length: " << length << " must be even" << endl;
      break;
    }
    for(int i = 0; i < (length/2) - 1; i++) {
      sections[i].setNeighbor(sections[i+1], direction);
      sections[i].setFlow(direction);
    }
    sections[(length/2)-1].setNeighbor(intSec1, direction);
    sections[(length/2)-1].setFlow(direction);
    sections[length/2] = intSec1;
    sections[(length/2)+1] = intSec2;
    intSec1.setNeighbor(intSec2, direction);
    intSec1.setFlow(direction);
    intSec2.setNeighbor(intSec2, direction);
    intSec2.setFlow(direction);

  }

  Lane::~Lane(){}





