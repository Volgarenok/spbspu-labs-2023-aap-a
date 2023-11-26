#include "searchLines.hpp"

isaychev::ulli_t isaychev::searchLines(const int * matrix, isaychev::ulli_t rs, isaychev::ulli_t cs)
{
  isaychev::ulli_t lineCount = 0;
  ulli_t lineCheck = cs;
  if (cs != 1)
  {
    isaychev::ulli_t countEq = 0;
    for (isaychev::ulli_t i = 0; i < rs * cs - 1; ++i)
    {
      int currElement = matrix[i];
      int nextElement = matrix[i+1];
      if (currElement == nextElement)
      {
        ++countEq;
      }
      if (((i + 1) % (lineCheck - 1)) == 0)
      {
        if (countEq == 0)
        {
          ++lineCount;
        }
        countEq = 0;
        lineCheck += cs;
        ++i;
      }
    }
  }
  else if (cs == 1)
  {
    lineCount = rs;
  }
  return lineCount;
}
