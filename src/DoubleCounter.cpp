#include "DoubleCounter.h"

void DoubleCounter::increment() {
  Counter::increment();
  Counter::increment();
}
