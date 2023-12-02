#include <limits>
//#include <iostream>
#include <fstream>
#include "matrix.hpp"
#include "readFromFile.hpp"

size_t rebdev::fillTheMatrix(long long int * array, size_t rows, size_t colums, std::ifstream & inputFile)
{
  for (size_t i = 0; i < (colums * rows); ++i)
  {
    if (!(inputFile >> array[i]))
    {
      return i;
    }
  }
  return (colums * rows);
}

size_t rebdev::findNumberOfLocalMax(long long int * arr, size_t rows, size_t colums)
{
  size_t numberOfLocalMax = 0;
  bool isLocalMax = 1;
  for (size_t i = 0; i < (colums * (rows-1)); ++i)
  {
    if (((i % colums) != 0) && ((i % colums) != (colums - 1)) && (i > (colums-1)))
    {
      isLocalMax = 1;
      for (int rowIndex = -1; rowIndex <= 1; ++rowIndex)
      {
        for (int columIndex = -1; columIndex <= 1; ++columIndex)
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
