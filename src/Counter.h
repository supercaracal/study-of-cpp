#ifndef SRC_COUNTER_H_
#define SRC_COUNTER_H_
#include <cstdlib>
#include <algorithm>
class Counter {
 public:
  Counter();
  Counter(Counter &c);
  ~Counter();
 private:
  int cnt;
 public:
  void increment();
  int get() const;
};
#endif // SRC_COUNTER_H_
