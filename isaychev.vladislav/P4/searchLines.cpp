#include "searchLines.hpp"

size_t searchLines(int * matrix, size_t rs, size_t cs)
{
  size_t counter = 1;
  const size_t one = 1;
  size_t i = 0;
  for (size_t j = 0; j < rs; ++j)
  {
    while (i < cs - one)
    {
      int currElement = matrix[i];
      int nextElement = matrix[i+1];
      if (currElement == nextElement)
      {
        ++counter;
      }
      ++i;
    }
  }
}
