#ifndef SRC_01_03_05_GAME_H_
#define SRC_01_03_05_GAME_H_
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include "state.h"
class game {
 public:
  game();
  game(const game& g);
  game& operator=(const game& g);
  virtual ~game();
  void load_stage(std::istream& is);
  bool load_failed() const;
  void start();
 private:
  std::vector<std::string>* m_stage;
  bool m_loaded;
  char read_key() const;
  void print_stage() const;
};
#endif // SRC_01_03_05_GAME_H_
