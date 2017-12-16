//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 	

#include "Vehicle.h"

#include <string>

using namespace std;

    Vehicle::Vehicle(string _type, double _probRight, double _probLeft, Lane* _lane, vector<Section*> _sections) {

    	currLane = _lane;
    	sections = _sections;

    	if( _type.compare("car") == 0 ) {
    		size = 2;
    	}
    	else if( _type.compare("suv") == 0 ) {
    		size = 3;
    	}
    	else if( _type.compare("truck") == 0 ) {
    		size = 4;
    	}

    	inIntersection = false; // Vehicles will spawn at the end of the lanes
    	nearIntersection = false;

    	probRight = _probRight;
    	probLeft = _probLeft;
    	probStraight = 1.0 - probRight - probLeft;
    }

    // TODO
    void Vehicle::decidePath(double _probRight, double _probLeft) {
    	path = 's';
    }

    bool Vehicle::canMove(char _direction) {

    	// Check if the section in the desired direction is occupied
    	bool pathBlocked;

    	if(_direction == 'l') {
			pathBlocked = frontSection->getLeftSection()->getOccupied();
    	}
    	else if(_direction == 'r') {
    		pathBlocked = frontSection->getRightSection()->getOccupied();
    	}
    	else {
    		pathBlocked = frontSection->getUpSection()->getOccupied();
    	}

    	// Get the current state of the traffic light in the Vehicle's lane
    	TrafficLight::Color lightColor = currLane->getTrafficLight().getColor();
    	bool lightIsGreen = (lightColor == 1);
    	nearIntersection = frontSection->getUpSection()->getNearIntersection();

    	/* If there is a Vehicle directly in front of it or the Vehicle is near 
    	*  the intersection and the light is not green, then the Vehicle cannot
    	*  legally move */
    	if (pathBlocked || (nearIntersection && !lightIsGreen)) {
    		return false;
    	}

    	// Otherwise, the Vehicle is permitted to move in the desired direction
    	return true;
    }

    void Vehicle::move() {

    	char direction = 's';

    	bool frontCanTurnRight = frontSection->getRightSection() != NULL;
    	bool frontCanTurnLeft = frontSection->getLeftSection() != NULL;
    	bool backCanTurnRight = backSection->getRightSection() != NULL;
    	bool backCanTurnLeft = backSection->getLeftSection() != NULL;


    	// Check if any section of the vehicle is in the intersection
		for(int i = 0; i < sections.size(); i++) {
			if(sections[i]->getInIntersection()){
				inIntersection = true;
				break;
			}
		}

    	// If the Vehicle is attempting to move while in the intersection, check
    	// if it should turn or continue straight
    	if(inIntersection) {
    		// If the Vehicle's path indicates that it will turn left or right,
    		// check if a turn needs to occur
    		if( (path == 'l' && frontCanTurnLeft) || (path == 'r' && frontCanTurnRight) ) {
    			direction = path;
    		}
    	}


    	else if(canMove(direction)) {
    		// HANDLE FRONT SECTION
    		// Set the front section of this vehicle one section forward
    		if(frontSection->getNearEdge()) {
    			// If the front and back sections are the same, move the vehicle
    			// out of view
    			if(backSection->getNearEdge()) {
    				backSection->setOccupied(false);
    				// Vehicle is out of view - delete it's front and back sections

    				// delete frontSection; //****** what about other sections -- figure out something here
    				// delete backSection;

    			}
    			// Move one section of the vehicle out of view 
    			else {
    				frontSection = frontSection->getDownSection();
    			}
			}
    		else if(path == 's') {
    			frontSection = frontSection->getUpSection();
    		}
    		else if (path == 'l' && frontCanTurnLeft) {
    			frontSection = frontSection->getLeftSection();
    		}
    		else if (path == 'r' && frontCanTurnRight) {
    			frontSection = frontSection->getRightSection();
    		}
    		// Set new front section to be occupied
    		frontSection->setOccupied(true);

    		// HANDLE BACK SECTION
    		// Set original back section to be unoccupied
    		backSection->setOccupied(false);
    		// Set the back section of this vehicle one section forward
    		if(path == 's') {
    			backSection = backSection->getUpSection();
    		}
    		else if (path == 'l' && backCanTurnLeft) {
    			backSection = backSection->getLeftSection();
    		}
    		else if (path == 'r' && backCanTurnRight) {
    			backSection = backSection->getRightSection();
    		}

    	}
    }