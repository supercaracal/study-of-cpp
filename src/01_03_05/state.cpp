#include "state.h"

state::state() {
}

state::state(const state& s) {
}

state::~state() {
}

state& state::operator=(const state& s) {
  return *this;
}

void state::set(char* data) {
  char* p;
  int y;
  int x;
  for (p = data, y = 0, x = 0; *p != '\0'; ++p) {
    m_objects.push_back(std::make_tuple(*p, y, x));
    ++x;
    if (*p == '\n') {
      ++y;
      x = 0;
    }
  }
}

std::string state::get() {
  std::sort(m_objects.begin(), m_objects.end(), *this);
  std::stringstream ss;
  std::vector<std::tuple<char, int, int>>::iterator it;
  for (it = m_objects.begin(); it != m_objects.end(); ++it) {
    ss << std::get<0>(*it);
  }
  return ss.str();
}

bool state::operator() (const std::tuple<char, int, int> a,
                        const std::tuple<char, int, int> b) {

  return (std::get<1>(a) < std::get<1>(b))
    || (std::get<1>(a) == std::get<1>(b) && std::get<2>(a) < std::get<2>(b));
}
