#include "game.h"

game::game() : m_loaded(false) {
  m_stage = new std::vector<std::string>;
}

game::game(const game& g) {
  m_stage = new std::vector<std::string>;
  std::copy(g.m_stage->begin(), g.m_stage->end(), std::back_inserter(*m_stage));
  m_loaded = g.m_loaded;
}

game& game::operator=(const game& g) {
  std::vector<std::string>* tmp_stg = new std::vector<std::string>;
  delete m_stage;
  m_stage = tmp_stg;
  std::copy(g.m_stage->begin(), g.m_stage->end(), std::back_inserter(*m_stage));
  m_loaded = g.m_loaded;
  return *this;
}

game::~game() {
  delete m_stage;
}

void game::load_stage(std::istream& is) {
  if (m_loaded) return;

  char buf[1024];
  while (is.good()) {
    is.getline(buf, sizeof buf);
    m_stage->push_back(buf);
    m_loaded = true;
  }
}

bool game::load_failed() const {
  return !m_loaded;
}

void game::start() {
  char key;
  while (true) {
    print_stage();
    key = read_key();
    if (key == 'q') {
      break;
    }
  }
}

char game::read_key() const {
  char c;
  std::cin >> c;
  return c;
}

void game::print_stage() const {
  for (unsigned int i = 0, s = m_stage->size() - 1; i < s; ++i) {
    std::cout << m_stage->at(i) << std::endl;
  }
}
