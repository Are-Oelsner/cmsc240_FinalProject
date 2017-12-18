//* CMSC240 Final Project : Section.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/18/2017

#include "Section.h"

Section::Section() {
  up = NULL;
  right = NULL;
  down = NULL;
  left = NULL;

  occupied = false;
  nearEdge = false;
  nearIntersection = false;
  inIntersection = false;
}

Section::~Section() {}

void Section::setNeighbor(Section* _section, int direction) {
  switch(direction) {
    case 1: this->up = _section; break;
    case 2: this->right = _section; break;
    case 3: this->down = _section; break;
    case 4: this->left = _section; break;
  }
}

void Section::printSection() {
  cout << "[";
  if(this->inIntersection ) { 
    if(this->occupied) 
      cout << "\033[1;31mi\033[0m"; // Occupied Intersection
    else
      cout << "I"; // Unoccupied intersection 
  }
  else if( this ->nearIntersection ) {
    if(this->occupied) 
      cout << "\033[1;31mn\033[0m"; // Occupied near intersection
    else
      cout << "N"; // unoccupied near intersection
  }
  else if( this->nearEdge ) {
    if(this->occupied) 
      cout << "\033[1;31me\033[0m"; // Occupied edge
    else
      cout << "E"; // unoccupied edge
  }
  else {
    if(this->occupied) 
      cout << "\033[1;31mO\033[0m";
    else
      cout << " ";
  }
  cout << "]";
}

//original function without color
void Section::printSection2() {
  cout << "[";
  if( this->inIntersection ) { 
    if(this->occupied) 
      cout << "i"; // Occupied Intersection
    else
      cout << "I"; // Unoccupied intersection 
  }
  else if( this ->nearIntersection ) {
    if(this->occupied) 
      cout << "n"; // Occupied near intersection
    else
      cout << "N"; // unoccupied near intersection
  }
  else if( this->nearEdge ) {
    if(this->occupied) 
      cout << "e"; // Occupied edge
    else
      cout << "E"; // unoccupied edge
  }
  else {
    if(this->occupied) 
      cout << "O";
    else
      cout << " ";
  }
  cout << "]";
}

Section*
Section::
getRight(int direction) {
  Section* tmp;
  switch(direction) {
    case 1: tmp = this->right;
    case 2: tmp = this->down;
    case 3: tmp = this->left;
    case 4: tmp = this->up;
  }
  if(tmp == NULL)
    return NULL;
  if(tmp->getNearIntersection()) 
    return NULL;
  return tmp;
}

Section*
Section::
getStraight(int direction) {
  switch(direction) {
    case 1: return this->up;
    case 2: return this->right;
    case 3: return this->down;
    case 4: return this->left;
  }
}

Section*
Section::
getLeft(int direction) {
  Section* tmp;
  switch(direction) {
    case 1: tmp = this->left;
    case 2: tmp = this->up;
    case 3: tmp = this->right;
    case 4: tmp = this->down;
  }
  if(this->getBack(direction) == NULL) 
    return NULL;
  if(this->getBack(direction)->getNearIntersection() == true)
    return NULL;
  return tmp;
}

Section*
Section::
getBack(int direction) {
  switch(direction) {
    case 1: return this->down;
    case 2: return this->left;
    case 3: return this->up;
    case 4: return this->right;
  }
}

// Original getDirection Functions, not constrained by traffic flow
Section*
Section::
getRightSection(int direction) {
  switch(direction) {
    case 1: return this->right;
    case 2: return this->down;
    case 3: return this->left;
    case 4: return this->up;
  }
}

Section*
Section::
getStraightSection(int direction) {
  switch(direction) {
    case 1: return this->up;
    case 2: return this->right;
    case 3: return this->down;
    case 4: return this->left;
  }
}

Section*
Section::
getLeftSection(int direction) {
  switch(direction) {
    case 1: return this->left;
    case 2: return this->up;
    case 3: return this->right;
    case 4: return this->down;
  }
}

Section*
Section::
getBackSection(int direction) {
  switch(direction) {
    case 1: return this->down;
    case 2: return this->left;
    case 3: return this->up;
    case 4: return this->right;
  }
}