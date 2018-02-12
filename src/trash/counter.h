#ifndef SRC_TRASH_COUNTER_H_
#define SRC_TRASH_COUNTER_H_
#include <cstdlib>
#include <algorithm>
class Counter {
 public:
  Counter();
  Counter(const Counter& c);
  ~Counter();
 private:
  int cnt;
 public:
  void increment();
  int get() const;
};
#endif  // SRC_TRASH_COUNTER_H_
