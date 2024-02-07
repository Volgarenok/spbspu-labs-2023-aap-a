#include "inputarray.h"
#include "allocatememory.h"

char * gladyshev::inputArray(std::istream& input)
{
  char currsym = 0;
  size_t len = 10;
  size_t counter = 0;
  char * baseArray = new char[len];
  input >> std::noskipws;
  while (input >> currsym)
  {
    if (currsym == '\n')
    {
      baseArray[counter] = '\0';
      break;
    }
    baseArray[counter] = currsym;
    if ((counter + 1) == len)
    {
      try
      {
        char * newArray = newMemory(baseArray, len);
        delete[] baseArray;
        baseArray = newArray;
        len += 10;
      }
      catch (const std::bad_alloc & e)
      {
        delete[] baseArray;
        throw;
      }
    }
    ++counter;
  }
  if (counter == 0)
  {
    delete[] baseArray;
    throw std::runtime_error("Lack of data");
  }
  input >> std::skipws;
  return baseArray;
}
