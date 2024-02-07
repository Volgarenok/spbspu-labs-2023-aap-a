#include "allocatememory.h"

char * gladyshev::newMemory(const char * basicar, size_t len)
{
  char * newarr = new char[len + 10]{};
  for (size_t i = 0; i < len; ++i)
  {
    newarr[i] = basicar[i];
  }
  return newarr;
}
