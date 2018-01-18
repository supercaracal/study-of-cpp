#include <iostream>
#include <string>

class Exception {
 public:
  explicit Exception(std::string str) : m_str(str) { }
  ~Exception() { delete m_str.c_str(); }
  std::string message() const { return m_str; }
 private:
  std::string m_str;
};

int main(int argc, char *argv[]) {
  try {
    throw new Exception("Oops!");
  } catch (Exception *ex) {
    std::cout << ex->message() << std::endl;
  }

  exit(0);
}
