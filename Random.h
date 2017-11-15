#ifndef __random_h__
#define __random_h__

#include <random>

class Random {
  protected:
    /// Private Variables
    static std::mt19937 rng;
    static std::uniform_int_distribution<int> randint01;
    static std::uniform_real_distribution<double> randdouble;

  public:
    /// Functions
    inline static int randint() { //inline means implementation is in header
      return Random::randint01(Random::rng);
    }
    inline static int randint(int a, int b) {
      double u = Random::randdouble(RAndom::rng);
      int mappedValue = a + (int)((b - a + 1)*u);
      return mappedValue;
    }
};

// Static members must be defined @ file-level scope

#endif
