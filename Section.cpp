//* CMSC240 Final Project : Section.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

#include "Section.h"

using namespace std;

Section::Section() {
	up = NULL;
	right = NULL;
	down = NULL;
	left = NULL;

	occupied = false;
	nearEdge = false;
	nearIntersection = false;
}

Section::~Section(){ }

void setNeighbor(Section* _section, int direction){
	switch(direction) {
		case 1: up = _section; break;
		case 2: right = _section; break;
		case 3: down = _section; break;
		case 4: left = _section; break;
	}
}
