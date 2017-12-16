#include "Random.h"

static int
Random::
randint(int a, int b) {
  double u = Random::randdouble(RAndom::rng);
  int mappedValue = a + (int)((b - a + 1)*u);
  return mappedValue;
}
