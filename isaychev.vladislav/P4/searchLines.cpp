#include "searchLines.hpp"

size_t searchLines(int * matrix, size_t rs, size_t cs)
{
  size_t lineCount = 0;
  if (cs != 1)
  {
    size_t countEq = 0;
    const size_t one = 1;
    for (size_t i = 0; i < rs*cs-one; ++i)
    {
      int currElement = matrix[i];
      int nextElement = matrix[i+1];
      if (currElement == nextElement)
      {
        ++countEq;
      }
      if (((i + one) % (cs - one)) == 0)
      {
        if(countEq == 0)
        {
          ++lineCount;
        }
        countEq = 0;
        i += 2;
      }
    }
  }
  else if (cs == 1)
  {
    lineCount = rs;
  }
  return lineCount;
}
