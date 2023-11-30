#include "sizeOfTypes.hpp"
#include <iostream>
#include <cstring>

size_t rebdev::findIntSize(int num)
{
  int num2 = num, counter = 0;
  while(num2 > 0)
  {
    counter += 1;
    num2 /= 10;
  }
  return counter;
}

size_t rebdev::findCharPointerSize(char * str)
{
  return strlen(str);
}
