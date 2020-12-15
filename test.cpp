#include <iostream>
#include <typeinfo>
using namespace std;
#include "alloc_in_class.h"
template <class T>
void hello(T a, int n) {
  cout << "the size of " << typeid(T).name() << " is " << sizeof(T) << endl;
  cout << "Creat " << n << " objects with new operator" << endl;
  T* array[n];
  for (int i = 0; i < n; i++) {
    array[i] = new T(i);
  }
  cout << "see their address" << endl;
  for (int i = 0; i < n; i++) {
    cout << array[i] << endl;
  }

  for (int i = 0; i < n; i++) {
    delete array[i];
  }
}

int main() {
  Test test;
  Compare compare;
  cout << "This is the result of Test (no cookie) " << endl;
  hello(Test(), 10);
  cout << "This is the result of Compare (with cookie) " << endl;
  hello(Compare(), 10);
  cout << endl;
  long* a[10];
  for (int i = 0; i < 10; i++) {
    a[i] = new long(i);
  }
  for (int i = 0; i < 10; i++) {
    cout << a[i] << endl;
    delete a[i];
  }
  return 0;
}