#ifndef SRC_TMPL_H_
#define SRC_TMPL_H_
#include <iostream>
template <typename TYPE> void FillArray(TYPE* array, int size, TYPE value) {
  for (int i = 0; i < size; ++i) {
    array[i] = value;
  }
}

template <typename TYPE> void ShowArray(TYPE* array, int size) {
  for (int i = 0; i < size; ++i) {
    std::cout << array[i] << std::endl;
  }
}
#endif // SRC_TMPL_H_
