#include <string>
#include "Tmpl.h"

int main(int argc, char *argv[]) {
  const int SIZE = 10;

  int i[SIZE];
  double d[SIZE];
  std::string s[SIZE];

  FillArray(i, SIZE, 1);
  FillArray<double>(d, SIZE, 2);
  FillArray<std::string>(s, SIZE, "hoge");

  ShowArray(i, SIZE);
  ShowArray(d, SIZE);
  ShowArray(s, SIZE);
}
