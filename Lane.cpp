//* CMSC240 Final Project : Lane.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 


#include "Lane.h"
#include <iostream>

Lane::Lane() {
}

Lane::Lane(int length, Section* intSec1, Section* intSec2, int direction) {
  cout << "Constructing lane: " << direction << endl;

	if(length % 2 != 0 || length < 12) {
		cout << "Error: length: " << length << " must be even and at least 12" << endl;
		exit(0);
	}

	int opposite = (direction+2) % 4; // opposite direction

	sections.push_back(new Section()); // first section in lane

	// adds sections before intersection
	for(int i = 1; i < (length/2) - 1; i++) { 
		sections.push_back(new Section());
		sections[i-1]->setNeighbor(sections[i], direction); // sets next neighbor
		sections[i]->setNeighbor(sections[i-1], opposite); // sets previous neighbor
    if( i == (length/2) - 2 ) {
      sections[i]->setNearIntersection(true);
    }
	}

	// adds intersection sections
  intSec1->setInIntersection(true);
  intSec2->setInIntersection(true);
	sections.push_back(intSec1);
	sections[(length/2)-1]->setNeighbor(sections[length/2], direction);
  cout << "Before suspected error" << endl;
	sections[length/2]->setNeighbor(sections[(length/2)-1], opposite); //TODO error here
  cout << "After suspected error" << endl;

	sections.push_back(intSec2);
	sections[length/2]->setNeighbor(sections[(length/2)+1], direction);
	sections[(length/2)+1]->setNeighbor(sections[length/2], opposite); 

	// adds sections after intersection
	for(int i = (length/2)+2; i < length; i++) { 
		sections.push_back(new Section());
		sections[i-1]->setNeighbor(sections[i], direction); // sets next neighbor
		sections[i]->setNeighbor(sections[i-1], opposite); // sets previous neighbor
    if( i == length-1 ) {
      sections[i]->setNearEdge(true);
    }
	}
	this->direction = direction;
  cout << "Finished constructing lane: " << direction << endl;
}

Lane::~Lane(){}

Section* Lane::getSection(int i) {
	return sections[i];
}

void
Lane::
printLane() {
  cout << "[";
  for(Section* sec : sections) {
    sec->printSection();
  }
  cout << "]";
}






