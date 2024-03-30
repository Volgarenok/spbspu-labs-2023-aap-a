#include "manageResources.hpp"

char * spiridonov::manageResources(const char* currentArray, size_t strOld, size_t strNew)
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
  return result;
}
