#include <limits>
#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "readFromFile.hpp"

void rebdev::filling(long long int * array, long long int rows,
  long long int colums, std::ifstream & inputFile)
{
  for (long long int i = 0; i < (colums * rows); ++i)
  {
    if (!(inputFile >> array[i]))
    {
      throw std::logic_error("Reading error: can't read from file");
    }
  }
}

long long int rebdev::localMax(long long int * arr, long long int rows, long long int colums)
{
  long long int numberOfLocalMax = 0;
  bool isLocalMax = 1;
  for (long long int i = 0; i < (colums * (rows-1)); ++i)
  {
    if (((i % colums) != 0) && ((i % colums) != (colums - 1)) && (i > (colums-1)))
    {
      isLocalMax = 1;
      for (long long int rowIndex = -1; rowIndex <= 1; ++rowIndex)
      {
        for (long long int columIndex = -1; columIndex <= 1; ++columIndex)
        {
          if ((rowIndex != 0) && (columIndex != 0))
          {
            if (arr[i] <= arr[i + colums * rowIndex + columIndex])
            {
              isLocalMax = 0;
              columIndex = 2;
              rowIndex = 2;
              break;
            }
          }
        }
      }
      numberOfLocalMax += isLocalMax;
    }
  }

  return numberOfLocalMax;
}
