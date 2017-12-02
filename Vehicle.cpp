//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 	

#include "Vehicle.h"

    Vehicle::Vehicle() {
    	inIntersection = false; // Vehicles will spawn at the end of the lanes
    	nearIntersection = false;
    	probRight = 
    	probLeft = 
    	probStraight = 1.0 - probRight - probLeft;

    }

    Vehicle::decidePath(double probRight, double probLeft) {

    	path = 's';
    }

    Vehicle::canMove(char direction) {

    	// Check if the section in the desired direction is occupied
    	bool pathBlocked;

    	if(direction == 'l') {
			pathBlocked = frontSection.getLeftSection().getOccupied();
    	}
    	else if(direction == 'r') {
    		pathBlocked = frontSection.getRightSection().getOccupied();
    	}
    	else {
    		pathBlocked = frontSection.getNextSection().getOccupied();
    	}

    	// Get the current state of the traffic light in the Vehicles's lane
    	string light = currLane.getTrafficLight();

    	/* If there is a Vehicle directly in front of it or the Vehicle is near 
    	*  the intersection and the light is not green, then the Vehicle cannot
    	*  legally move */
    	if (pathBlocked || (nearIntersection && !light.equals("green"))) {
    		return false;
    	}

    	// Otherwise, the Vehicle is permitted to move in the desired direction
    	return true;
    }

    Vehicle::move() {

    	string direction = "";
    	bool canTurnRight = frontSection.hasRightSection();
    	bool canTurnLeft = frontSection.hasLeftSection();
    	// If the Vehicle is attempting to move while in the intersection, check
    	// if it should turn or continue straight
    	if(inIntersection) {
    		// If the Vehicle's path indicates that it will turn left or right,
    		// check if a turn needs to occur
    		if(path == 'l' && canTurnLeft || path == 'r' && canTurnRight) {
    			direction = path;
    		}
    		else {
    			direction = 's';
    		}
    	}

    	if(canMove(direction)) {
    		// Set the new front section of this vehicle one section forward
    		frontSection = frontSection.getNextSection();

    		// If the vehicle has entered the intersection
    		if(frontSection.getInIntersection()) {
    			inIntersection = true;
    		}
    		else {
    			inIntersection = false;
    		}
    		// Set new front section to be occupied
    		frontSection.setOccupied(true);
    		// Set original back section to be unoccupied
    		backSection.setOccupied(false);
    		backSection = backSection.getNextSection();
    	}
    }