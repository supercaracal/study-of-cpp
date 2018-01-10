#ifndef SRC_DOUBLECOUNTER_H_
#define SRC_DOUBLECOUNTER_H_
#include <cstdlib>
#include <algorithm>
#include "Counter.h"
class DoubleCounter : public Counter {
 public:
  void increment();
};
#endif // SRC_DOUBLECOUNTER_H_
