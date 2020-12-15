#include "alloc_in_class.h"

std::size_t Test::chunk = 10;
Test* Test::freeStore = 0;

std::size_t Compare::chunk = 10;
Compare* Compare::freeStore = 0;
void* Test::operator new(std::size_t size) {
  if (size != sizeof(Test))
    return ::operator new(size);  // in case that there is inheritance
  Test* p;
  if (freeStore == 0) {
    freeStore = (Test*)::operator new(chunk* size);
    p = freeStore;
    for (int i = 1; i < chunk - 1; i++) {
      (p + i)->next = (p + i + 1);
    }
    freeStore = p + 1;
    return p;
  } else {
    p = freeStore;
    freeStore++;
    return p;
  }
}

void Test::operator delete(void* p, std::size_t size) {  // only recycle
  ((Test*)p)->next = freeStore;
  freeStore = (Test*)p;
}