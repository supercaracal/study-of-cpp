#ifndef SRC_01_03_05_STATE_H_
#define SRC_01_03_05_STATE_H_
#include <iostream>
#include <vector>
#include <tuple>
#include <algorithm>
#include <sstream>
#include <string>
#include <utility>
// FIXME: cpplint runtime/references
class state {
 public:
  struct pos { int y; int x; };
  state();
  state(const state& s);
  virtual ~state();
  state& operator=(const state& s);
  bool operator() (const std::tuple<char, int, int> a,
                   const std::tuple<char, int, int> b);
  void set(char* data);
  std::string get();
  void move(char key);
  bool is_goal();

 private:
  std::vector<std::tuple<char, int, int>> m_objects;
  pos convert_key_to_delta(char key);
  std::tuple<char, int, int>& find_player();
  std::tuple<char, int, int>& find_object(pos p);
  bool on_wall(pos p);
  bool on_baggage(pos p);
  bool on_goal(pos p);
  void move_player(std::tuple<char, int, int>& player,
                   std::tuple<char, int, int>& destination);
  bool move_baggage(std::tuple<char, int, int>& baggage,
                    std::tuple<char, int, int>& destination);
};
#endif  // SRC_01_03_05_STATE_H_
