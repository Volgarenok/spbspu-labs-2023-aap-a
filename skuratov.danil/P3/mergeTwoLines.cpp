#include "mergeTwoLines.hpp"

#include <cstddef>
#include <cstring>

char* mergeTwoLines(char* line1, char* line2)
{
  size_t size1 = strlen(line1);
  size_t size2 = strlen(line2);
  size_t size = size1 + size2;

  char* result = new char[size + 1];

  size_t i = 0;
  for (size_t r = 0; r < size1; ++r)
  {
    result[i] = line1[r];
    ++i;
  }
  for (size_t r = 0; r < size2; ++r)
  {
    result[i] = line2[r];
    ++i;
  }
  result[i] = '\0';
  return result;
}
