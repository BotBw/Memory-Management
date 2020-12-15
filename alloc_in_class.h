#ifndef ALLOC_IN_CLASS_H
#define ALLOC_IN_CLASS_H
#include <cctype>  // typedef unsigned size_t
class Test { // 8(the union)
  union {  // embedded pointer
    Test* next;
    int data;
  };

 private:
  static std::size_t chunk;  // number of Test in pool
  static Test* freeStore;    // head of the memory pool

 public:
  Test() : data(0) {}
  Test(int _data) : data(_data) {}
  static void* operator new(std::size_t size);  // overload operator new, using
                                                // simple memory pool design
  static void operator delete(
      void* p,
      std::size_t size);  // only recycle used memory without invoking free()
};

class Compare {  // same member except function overload
  union {
    Compare* next;
    int data;
  };

 private:
  static std::size_t chunk;
  static Compare* freeStore;

 public:
  Compare() : data(0) {}
  Compare(int _data) : data(_data) {}
  // static void* operator new(std::size_t size);
  // static void operator delete(void* p, std::size_t size);
};

#endif