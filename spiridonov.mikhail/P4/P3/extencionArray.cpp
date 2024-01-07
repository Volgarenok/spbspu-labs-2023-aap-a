#include <iostream>
#include "extencionArray.hpp"

char * spiridonov::extencionArray(const char* currentArray, const size_t strOld, size_t strNew)
{
  char* result = new char[strNew];
  for (size_t i = 0; i < strOld; ++i)
  {
    result[i] = currentArray[i];
  }
  for (size_t i = strOld; i < strNew; ++i)
  {
    result[i] = 0;
  }
  delete[] currentArray;
  return result;
}
