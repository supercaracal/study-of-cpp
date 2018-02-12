#include "double_counter.h"

void DoubleCounter::increment() {
  Counter::increment();
  Counter::increment();
}
