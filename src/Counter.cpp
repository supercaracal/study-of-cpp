#include "Counter.h"

Counter::Counter() {
  cnt = 0;
}

Counter::Counter(Counter &c) {
  cnt = c.get();
}

Counter::~Counter() {
  cnt = 0;
}

void Counter::increment() {
  ++cnt;
}

int Counter::get() const {
  return cnt;
}
