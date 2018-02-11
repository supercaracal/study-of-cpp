#include "headers/game.h"

game::game(const int height, const int width) : m_loaded(false), m_height(height), m_width(width) {
  m_sl = new std::string[m_height];
}

game::~game() {
  delete[] m_sl;
}

void game::load_stage(std::istream& is) {
  char buf[m_width];
  for (int i = 0; is.good(); i++, m_loaded = true) {
    is.getline(buf, m_width);
    m_sl[i] = buf;
  }
}

bool game::load_failed() const {
  return !m_loaded;
}

void game::print_stage() const {
  for (int i = 0; !m_sl[i].empty(); ++i) {
    std::cout << m_sl[i] << std::endl;
  }
}
