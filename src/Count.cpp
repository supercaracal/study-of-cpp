#include <iostream>
#include "Counter.h"
#include "DoubleCounter.h"

int main(int argc, char *argv[]) {
  Counter c;
  c.increment();
  c.increment();
  c.increment();
  std::cout << c.get() << std::endl;

  DoubleCounter dc;
  dc.increment();
  dc.increment();
  dc.increment();
  std::cout << dc.get() << std::endl;
}
