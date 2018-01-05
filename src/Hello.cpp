#include <iostream>

int main() {
  char name[1024];
  std::cout << "What your name? > " << std::flush;
  std::cin >> name;
  std::cout << "Hello " << name << std::endl;
}
