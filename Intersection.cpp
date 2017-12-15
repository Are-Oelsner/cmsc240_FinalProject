//* CMSC240 Final Project : Intersection.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:12/14/17

#include "Intersection.h"

Intersection::
Intersection() {
	length = 20; //default length

	// Creates intersection sections
	NW = new Section();
	NE = new Section();
	SE = new Section();
	SW = new Section();

	// Creates Lanes
	north(length, SE, NE, 1);
	east(length, SW, SE, 2);
	south(length, NW, SW, 3);
	west(length, NE, NW, 4);
}

Intersection::
Intersection(int length) {
	// Creates intersection sections
	NW = new Section();
	NE = new Section();
	SE = new Section();
	SW = new Section();

	// Creates Lanes
	north(length, SE, NE, 1);
	east(length, SW, SE, 2);
	south(length, NW, SW, 3);
	west(length, NE, NW, 4);
}

//TODO? 
Intersection::
~Intersection() {
}
