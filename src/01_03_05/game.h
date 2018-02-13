#ifndef SRC_01_03_05_GAME_H_
#define SRC_01_03_05_GAME_H_
#include <iostream>
#include <sstream>
#include "state.h"
class game {
 public:
  game();
  game(const game& g);
  game& operator=(const game& g);
  virtual ~game();
  void load_stage(std::istream& is);
  bool load_failed() const;
  void run();
 private:
  bool m_loaded;
  state m_state;
  void print_stage();
};
#endif  // SRC_01_03_05_GAME_H_
