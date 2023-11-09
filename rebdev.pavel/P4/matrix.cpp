#include <limits>
#include "matrix.hpp"
#include "forFile.hpp"

void rebdev::filling(long long int * array, long long int rows,
  long long int colums, std::ifstream & inputFile)
{
  for (long long int i = 0; i < (colums * rows); ++i)
  {
    array[i] = readFromFileLLI(inputFile);
  }
}

long long int rebdev::localMax(long long int * arr, long long int rows, long long int colums)
{
  long long int numberOfLocalMax = 0;
  bool isLocalMax = 1;
  for (long long int i = 0; i < (colums * rows); ++i)
  {
    isLocalMax = 1;
    for (long long int rowIndex = -1; rowIndex <= 1; ++rowIndex)
    {
      for (long long int columIndex = -1; columIndex <= 1; ++columIndex)
      {
        //Проверка, является ли номер элемента корректным
        if(isNumberOfElementIsCorrect(i, columIndex, rowIndex, rows, colums) == 1)
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

  return numberOfLocalMax;
}

bool rebdev::isNumberOfElementIsCorrect(long long int itemOfNumber, long long int columIndex,
  long long int rowIndex, long long int rows, long long int colums)
{
  if ((columIndex == 0) && (rowIndex == 0))
  {
    return 0;
  }

  if ((itemOfNumber + colums * rowIndex + columIndex) >= 0)
  {
    if ((itemOfNumber + colums * rowIndex + columIndex) < (colums * rows))
    {
      if (!(((itemOfNumber % colums) == 0) && (columIndex == -1)))
      {
        if (!(((itemOfNumber % colums) == (colums - 1)) && (columIndex == 1)))
        {
          return 1;
        }
      }
    }
  }

  return 0;
}
