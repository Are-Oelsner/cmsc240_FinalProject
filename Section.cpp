//* CMSC240 Final Project : Section.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 

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
  if( this->inIntersection ) {
    cout << " I ";
  }
  if( this ->nearIntersection ) {
    cout << " N ";
  }
  if( this->occupied ) {
    cout << " O ";
  }
  if( this->nearEdge ) {
    cout << " E ";
  }
  cout << "] ";
}

Section*
Section::
getRight(int direction) {
  switch(direction) {
    case 1: return this->right;
    case 2: return this->down;
    case 3: return this->left;
    case 4: return this->up;
  }
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
  switch(direction) {
    case 1: return this->left;
    case 2: return this->up;
    case 3: return this->right;
    case 4: return this->down;
  }
}

Section*
Section::
getLeft(int direction) {
  switch(direction) {
    case 1: return this->down;
    case 2: return this->left;
    case 3: return this->up;
    case 4: return this->right;
  }
}




