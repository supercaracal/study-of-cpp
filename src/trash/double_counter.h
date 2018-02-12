#ifndef SRC_TRASH_DOUBLE_COUNTER_H_
#define SRC_TRASH_DOUBLE_COUNTER_H_
#include <cstdlib>
#include <algorithm>
#include "counter.h"
class DoubleCounter : public Counter {
 public:
  void increment();
};
#endif  // SRC_TRASH_DOUBLE_COUNTER_H_
