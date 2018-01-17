#include <iostream>
#include <string>

class HogeError {
 public:
  HogeError() { m_str = "hogehoge"; }
  ~HogeError() { delete m_str.c_str(); }
  std::string message() const { return m_str; }
 private:
  std::string m_str;
};

int main(int argc, char *argv[]) {
  try {
    throw new HogeError();
  } catch (HogeError *hoge) {
    std::cout << hoge->message() << std::endl;
  }

  exit(0);
}
