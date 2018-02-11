#ifndef SRC_01_03_05_HEADERS_GAME_H_
#define SRC_01_03_05_HEADERS_GAME_H_
#include <iostream>
#include <string>
class game {
 public:
  game(const int height, const int width);
  ~game();
  void load_stage(std::istream& is);
  bool load_failed() const;
  void print_stage() const;
 private:
  std::string *m_sl;
  bool m_loaded;
  const int m_height;
  const int m_width;
};
#endif // SRC_01_03_05_HEADERS_GAME_H_
