#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <stdlib.h>
#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

template <typename T>
void printVector(T vec) {
  int len = vec.size();
  for (int i = 0; i < len; i++) {
    cout << vec[i];
  }
  cout << endl;
}

#endif /* MYVECTOR_H */
