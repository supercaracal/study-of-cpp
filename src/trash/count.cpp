#include <iostream>
#include "counter.h"
#include "double_counter.h"

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
