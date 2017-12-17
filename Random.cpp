//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#include "Random.h"

	static int Random::randint(int a, int b) {
	  double u = Random::randdouble(Random::rng);
	  int mappedValue = a + (int)((b - a + 1)*u);
	  return mappedValue;
	}
