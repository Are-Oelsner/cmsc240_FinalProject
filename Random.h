#ifndef __random_h__
#define __random_h__

#include<random>

class Random {
  protected:
  static std::mt19937 rng(seed);

};

#endif
