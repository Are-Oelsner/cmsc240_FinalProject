//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date: 12/18/2017

#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>

//******************************************************************************
//* This class provides Random number functionality
class Random {

  protected:

    //**************************************************************************
    //* Private Variables

    static std::mt19937 rng;
    static std::uniform_int_distribution<int> randint01;
    static std::uniform_real_distribution<double> randdouble;

  public:

    //**************************************************************************
    //* Functions

    //* Returns a random integer
    //* @return a random integer
    inline static int randint() { return Random::randint01(Random::rng); }

    //* Returns a random integer in the range a-b
    //* @param  a   minimum int in range
    //* @param  b   maximum int in range
    //* @return a random integer in the range a-b
    static int randint(int a, int b){
      double u = Random::randdouble(Random::rng);
      int mappedValue = a + (int)((b - a + 1)*u);
      return mappedValue;
    }

    //* Returns a random double in the range a-b
    //* @param  a   minimum double in range
    //* @param  b   maximum double in range
    //* @return a random double in the range a-b
    static double randDouble(double min, double max){
      double before = rand() % (int)max + (int)min;
      double after = (double)rand() / RAND_MAX;
      double result = before + after;
      if (result < min || result > max) {
          result = randDouble(min, max);
      }
      return result;
    }
};

#endif
