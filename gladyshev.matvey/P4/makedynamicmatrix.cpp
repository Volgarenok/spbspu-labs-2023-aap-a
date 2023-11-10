#include "makedynamicmatrix.h"

int ** gladyshev::goDynamicMatrix(std::fstream &input, size_t rows, size_t cols)
{
  int ** array = new int *[rows];
  for (size_t i = 0; i < rows; i++)
  {
    array[i] = new int[cols];
    for (size_t j = 0; j < cols; j++)
    {
      if (!input.eof())
      {
        if (!input)
        {
          throw std::bad_alloc("Error in reading");
        }
      }
      else
      {
        throw std::runtime_error("Out of data");
      }
      input >> array[i][j];
    }
  }
  return array;
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
