#ifndef MYVECTOR_H
#define MYVECTOR_H

#include <vector>
#include <iostream>
using namespace std;

template<typename T>
void printVector(T vec){
  int len = vec.size();
  for (int i = 0; i < len; i++) {
    cout << vec[i];
  }
  cout << endl;
}


#endif /* MYVECTOR_H */
