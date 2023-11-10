#include "makedynamicmatrix.h"

int gladyshev::goDynamicMatrix(std::fstream &input, int ** array, size_t rows, size_t cols)
{
  try
  {
    for (size_t i = 0; i < rows; i++)
    {
      array[i] = new int[cols];
      for (size_t j = 0; j < cols; j++)
      {
        if (!input.eof())
        {
          if (!input)
          {
            return 2;
          }
        }
        else
        {
          return 4;
        }
        input >> array[i][j];
      }
    }
    return 2;
  }
  catch (const std::bad_alloc &)
  {
    gladyshev::freeMatrix(array, rows, cols);
    throw;
  }
}

void gladyshev::freeMatrix(int ** matrix, size_t rows)
{
  for (size_t i = 0; i < rows; ++i)
  {
    delete [] matrix[i];
  }
  delete [] matrix;
}

void gladyshev::freeMatrix(int ** matrix, size_t rows, size_t)
{
  gladyshev::freeMatrix(matrix, rows);
}
