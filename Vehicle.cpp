//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 	

#include "Vehicle.h"
#include "Parser.h"

    Vehicle::Vehicle() {
    	inIntersection = false; // Vehicles will spawn at the end of the lanes
    	nearIntersection = false;
    	probRight = parser.getRight_Prob();
    	probLeft = parser.getLeft_Prob();
    	probStraight = 1.0 - probRight - probLeft;
    	size = 2; // Default constructor spawns basic car
    }

    Vehicle::Vehicle(string type) {
    	if(type.equals("car") {
    		size = 2;
    	}
    	else if(type.equals("suv") {
    		size = 3;
    	}
    	else if(type.equals("truck") {
    		size = 4;
    	}
    	inIntersection = false; // Vehicles will spawn at the end of the lanes
    	nearIntersection = false;
    	probRight = getRight_Prob();
    	probLeft = getLeft_Prob();
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
    	nearIntersection = frontSection.getNextSection().getNearIntersection();

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

    	char direction = 's';

    	bool frontCanTurnRight = frontSection.hasRightSection();
    	bool frontCanTurnLeft = frontSection.hasLeftSection();
    	bool backCanTurnRight = backSection.hasRightSection();
    	bool backCanTurnLeft = backSection.hasLeftSection();

    	// Check if any section of the vehicle is in the intersection
		for(int i = 0; i < sections.length; i++) {
			if(section.getInIntersection()){
				inIntersection = true;
				break;
			}
		}

    	// If the Vehicle is attempting to move while in the intersection, check
    	// if it should turn or continue straight
    	if(inIntersection) {
    		// If the Vehicle's path indicates that it will turn left or right,
    		// check if a turn needs to occur
    		if(path == 'l' && canTurnLeft || path == 'r' && canTurnRight) {
    			direction = path;
    		}
    	}


    	else if(canMove(direction)) {
    		// HANDLE FRONT SECTION
    		// Set the front section of this vehicle one section forward
    		if(frontSection.getNearEdge()) {
    			// If the front and back sections are the same, move the vehicle
    			// out of view
    			if(backSection.getNearEdge()) {
    				backSection.setOccupied(false);
    				// Vehicle is out of view - delete it's front and back sections
    				delete frontSection; //****** what about other sections -- figure out something here
    				delete backSection;
    			}
    			// Move one section of the vehicle out of view 
    			else if {
    				frontSection = frontSection.getPrevSection();
    			}
			}
    		else if(path == 's') {
    			frontSection = frontSection.getNextSection();
    		}
    		else if (path == 'l' && frontCanTurnLeft) {
    			frontSection = frontSection.getLeftSection();
    		}
    		else if (path == 'r' && frontCanTurnRight) {
    			frontSection = frontSection.getRightSection();
    		}
    		// Set new front section to be occupied
    		frontSection.setOccupied(true);

    		// HANDLE BACK SECTION
    		// Set original back section to be unoccupied
    		backSection.setOccupied(false);
    		// Set the back section of this vehicle one section forward
    		if(path == 's') {
    			backSection = backSection.getNextSection();
    		}
    		else if (path == 'l' && backCanTurnLeft) {
    			backSection = backSection.getLeftSection();
    		}
    		else if (path == 'r' && backCanTurnRight) {
    			backSection = backSection.getRightSection();
    		}

    	}
    }