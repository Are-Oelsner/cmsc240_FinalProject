/* Section Test file
 */

#include "Section.h"
#include <iostream>
using namespace std;

int main() {
	// Testing Default Constructor
	Section* section = new Section();

	// Testing Default Traffic Flow
	cout << "getNorth(): " << section->getNorth() << ". [false]" << endl;
	cout << "getEast(): " << section->getEast() << ". [false]" << endl;
	cout << "getSouth(): " << section->getSouth() << ". [false]" << endl;
	cout << "getWest(): " << section->getWest() << ". [false]" << endl;

	// Testing Neighbors on Default //TODO this might not print null
	cout << "getUpsection(): " << section->getUpSection() << ". [NULL]" << endl;
	cout << "getRightSection(): " << section->getRightSection() << ". [NULL]" << endl;
	cout << "getDownSection(): " << section->getDownSection() << ". [NULL]" << endl;
	cout << "getLeftSection(): " << section->getLeftSection() << ". [NULL]" << endl;

	// Testing Getters on Default
	cout << "getOccupied(): " << section->getOccupied() << ". [false]" << endl;
	cout << "getNearIntersection(): " << section->getNearIntersection() << ". [false]" << endl;
	cout << "getNearEdge(): " << section->getNearEdge() << ". [false]" << endl;

	// Creating test neighbor sections
	Section* uNeighbor = new Section();
	Section* rNeighbor = new Section();
	Section* dNeighbor = new Section();
	Section* lNeighbor = new Section();

	// Testing Setters
	section->setNeighbor(uNeighbor, 1);
	section->setNeighbor(rNeighbor, 2);
	section->setNeighbor(dNeighbor, 3);
	section->setNeighbor(lNeighbor, 4);

	section->setOccupied(true);
	section->setNearEdge(true);
	section->setNearIntersection(true);
	
	// Testing Traffic Flow
	cout << "getNorth(): " << section->getNorth() << ". [true]" << endl;
	cout << "getEast(): " << section->getEast() << ". [true]" << endl;
	cout << "getSouth(): " << section->getSouth() << ". [true]" << endl;
	cout << "getWest(): " << section->getWest() << ". [true]" << endl;

	// Testing Neighbors //TODO might need to write print method 
	cout << "getUpSection(): " << section->getUpSection() << ". [something]" << endl;
	cout << "getRightSection(): " << section->getRightSection() << ". [something]" << endl;
	cout << "getDownSection(): " << section->getDownSection() << ". [something]" << endl;
	cout << "getLeftSection(): " << section->getLeftSection() << ". [something]" << endl;

	// Testing Getters 
	cout << "getOccupied(): " << section->getOccupied() << ". [true]" << endl;
	cout << "getNearIntersection(): " << section->getNearIntersection() << ". [true]" << endl;
	cout << "getNearEdge(): " << section->getNearEdge() << ". [true]" << endl;
}
