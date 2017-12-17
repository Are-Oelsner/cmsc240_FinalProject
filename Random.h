//* CMSC240 Final Project : Vehicle.cpp
//* Authors: Are Oelsner, Maddie Shea, Ryan Jennings
//* Date:

#ifndef __RANDOM_H__
#define __RANDOM_H__

#include <random>

//******************************************************************************
//* TODO - Random class description
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

    inline static int randint() { return Random::randint01(Random::rng); }

    static int randint(int a, int b);
};

#endif
