#include "game.h"

game::game() : m_loaded(false) {
}

game::game(const game& g) {
  m_loaded = g.m_loaded;
  m_state = g.m_state;
}

game& game::operator=(const game& g) {
  m_loaded = g.m_loaded;
  m_state = g.m_state;
  return *this;
}

game::~game() {
}

void game::load_stage(std::istream& is) {
  if (m_loaded || is.fail()) return;

  is.seekg(0, is.end);
  int length = is.tellg();
  is.seekg(0, is.beg);
  char* buffer = new char[length];
  is.read(buffer, length);
  m_state.set(buffer);
  m_loaded = true;
  delete buffer;
}

bool game::load_failed() const {
  return !m_loaded;
}

void game::run() {
  char key;
  while (true) {
    print_stage();
    if (m_state.is_goal()) {
      std::cout << "GOAL!!" << std::endl;
      break;
    }
    std::cin >> key;
    if (key == 'q') {
      break;
    } else {
      m_state.move(key);
    }
  }
}

void game::print_stage() {
  std::cout << m_state.get() << "w:up z:down a:left s:right q:end" << std::endl;
}
