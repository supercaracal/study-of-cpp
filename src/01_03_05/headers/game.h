#ifndef SRC_01_03_05_HEADERS_GAME_H_
#define SRC_01_03_05_HEADERS_GAME_H_
#include <iostream>
#include <string>
#include <vector>
class game {
 public:
  game();
  game(const game& g);
  game& operator=(const game& g);
  virtual ~game();
  void load_stage(std::istream& is);
  bool load_failed() const;
  void print_stage() const;
 private:
  std::vector<std::string>* m_stage;
  bool m_loaded;
};
#endif // SRC_01_03_05_HEADERS_GAME_H_
