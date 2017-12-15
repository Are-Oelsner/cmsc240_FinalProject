//* CMSC240 Final Project : Lane.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:12/14/17

#include "Lane.h"

Lane::Lane() {
}

Lane::
Lane(int length, Section* intSec1, Section* intSec2, int direction) {
	if(length % 2 != 0) {
		cout << "Error: length: " << length << " must be even" << endl;
		break;
	}
	int opposite = (direction+2) % 4; // opposite direction

	sections.push_back(new Section()); // first section in lane

	// adds sections before intersection
	for(int i = 1; i < (length/2) - 1; i++) { 
		sections.push_back(new Section());
		sections[i-1].setNeighbor(sections[i], direction); // sets next neighbor
		sections[i].setNeighbor(sections[i-1], opposite); // sets previous neighbor
	}

	// adds intersection sections
	sections.push_back(intSec1);
	sections[(length/2)-1].setNeighbor(sections[length/2], direction);
	sections[length/2].setNeighbor(sections[(length/2)-1], opposite);

	sections.push_back(intSec2);
	sections[length/2].setNeighbor(sections[(length/2)+1], direction);
	sections[(length/2)+1].setNeighbor(sections[length/2], opposite); 

	// adds sections after intersection
	for(int i = (length/2)+2; i < length; i++) { 
		sections.push_back(new Section());
		sections[i-1].setNeighbor(sections[i], direction); // sets next neighbor
		sections[i].setNeighbor(sections[i-1], opposite); // sets previous neighbor
	}
	this.direction = direction;
}

Lane::~Lane(){}

Section*
lane::
getSection(int i) {
	return sections[i];
}






