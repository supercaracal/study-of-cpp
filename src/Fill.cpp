#include "Tmpl.h"

int main(int argc, char *argv[]) {
  const int SIZE = 10;

  int i[SIZE];
  double d[SIZE];

  FillArray(i, SIZE, 1);
  FillArray<double>(d, SIZE, 2);

  ShowArray(i, SIZE);
  ShowArray(d, SIZE);
}
