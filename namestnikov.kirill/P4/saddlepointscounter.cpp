#include "saddle_points_counter.hpp"
#include <new>

int * namestnikov::getMaxColArray(size_t result, size_t cols, const int * matrix)
{
  int * maxCol = new int[result];
  for (size_t j = 0; j < cols; ++j)
  {
    maxCol[j] = matrix[j];
    for (size_t i = 0; i < result; i += cols)
    {
      if (matrix[j + i] > maxCol[j])
      {
        maxCol[j] = matrix[j + i];
      }
    }
  }
  return maxCol;
}

int * namestnikov::getMinRowArray(size_t result, size_t cols, const int * matrix)
{
  int * minRow = new int[result];
  for (size_t i = 0; i < result; i += cols)
  {
    minRow[i]  = matrix[i];
    for (size_t j = 0; j < cols; ++j)
    {
      if (matrix[i + j] < minRow[i])
      {
        minRow[i] = matrix[i + j];
      }
    }
  }
  return minRow;
}

size_t namestnikov::countSaddlePoints(const int * matrix, const int * maxCol, const int * minRow, size_t result, size_t cols)
{
  size_t count = 0;
  for (size_t i = 0; i < result; i += cols)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      if ((matrix[i + j] == minRow[i]) && (matrix[i + j] == maxCol[j]))
      {
        ++count;
      }
    }
  }
  return count;
}
