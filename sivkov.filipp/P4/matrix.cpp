#include "matrix.hpp"
#include <memory>

void freeMatrix(int** m, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete[] m[i];
  }
  delete[] m;
}

int ** createMatrix(size_t rows, size_t cols)
{
  int ** rowsptrs = new int* [rows];
  for (size_t i = 0; i < rows; ++i)
  {
    rowsptrs[i] = nullptr;
  }
  try
  {
    for (size_t i = 0; i < rows; ++i)
    {
      rowsptrs[i] = new int[cols];
    }
    return rowsptrs;
  }
  catch (const std::bad_alloc&)
  {
    freeMatrix(rowsptrs, rows);
    throw;
  }
}
