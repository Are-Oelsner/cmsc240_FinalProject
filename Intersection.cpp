//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#include "Intersection.h"

Intersection::
Intersection() {
  sectionGrid[10][10];

  sectionGrid[6][9].setUp(sectionGrid[6][9]);
  sectionGrid[6][9].setNorth(true);

  sectionGrid[9][5].setLeft(sectionGrid[8][5]);
  sectionGrid[9][5].setWest(true);

  sectionGrid[5][0].setDown(sectionGrid[5][1]);
  sectionGrid[5][0].setSouth(true);

  sectionGrid[0][6].setRight(sectionGrid[1][6]);
  sectionGrid[0][6].setEast(true);

  for(int i = 1; i < 10; i++) {
    sectionGrid[5][i].setUp(sectionGrid[5][i-1]); // sets southbound up neighbors
    sectionGrid[i][6].setLeft(sectionGrid[i-1][6]); // sets eastbound left neighbors
    sectionGrid[10-(i+1)][5].setRight(sectionGrid[10-i][5]); // sets westbound right neighbors
    sectionGrid[6][10-(i+1)].setDown(sectionGrid[6][10-i]); // sets northbound down neighbors

    sectionGrid[5][i].setSouth(true); // sets southbound traffic flow
    sectionGrid[i][6].setEast(true); // sets eastbound traffic flow
    sectionGrid[10-i][5].setWest(true); // sets westbound traffic flow
    sectionGrid[6][10-i].setNorth(true); // sets northbound traffic flow
  }
  for(int i = 0; i < 9; i++) {
    sectionGrid[5][i].setDown(sectionGrid[5][i+1]); // sets southbound down neighbors
    sectionGrid[i][6].setRight(sectionGrid[i+1][6]); // sets eastbound left neighbors
    sectionGrid[10-i][5].setLeft(sectionGrid[10-(i+1)][5]); // sets westbound right neighbors
    sectionGrid[6][10-i].setUp(sectionGrid[6][10-(i+1)]); // sets northbound down neighbors

    sectionGrid[5][i].setSouth(true); // sets southbound traffic flow
    sectionGrid[i][6].setEast(true); // sets eastbound traffic flow
    sectionGrid[10-i][5].setWest(true); // sets westbound traffic flow
    sectionGrid[6][10-i].setNorth(true); // sets northbound traffic flow
  }

    sectionGrid[10-(i+1)][5].setWest(true); //Sets westbound lane traffic flow
    sectionGrid[i][6].setEast(true); //Sets eastbound lane traffic flow
    sectionGrid[10-(i+1)][5].
    sectionGrid[i][6]
  sectionGrid[0][0] = 
