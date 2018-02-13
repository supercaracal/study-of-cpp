#ifndef SRC_01_03_05_STATE_H_
#define SRC_01_03_05_STATE_H_
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <sstream>
#include <string>
class state {
 public:
  state();
  state(const state& s);
  virtual ~state();
  state& operator=(const state& s);
  void set(char* data);
  std::string get();
  bool operator() (const std::tuple<char, int, int> a,
                   const std::tuple<char, int, int> b);
 private:
  std::vector<std::tuple<char, int, int>> m_objects;
};
#endif  // SRC_01_03_05_STATE_H_
