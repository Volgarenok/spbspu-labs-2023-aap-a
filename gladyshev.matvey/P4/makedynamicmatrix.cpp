#include "makedynamicmatrix.h"

int ** gladyshev::goDynamicMatrix(std::fstream &input, size_t rows, size_t cols)
{
  int ** array = new int *[rows];
  try
  {
    for (size_t i = 0; i < rows; i++)
    {
      array[i] = new int[cols];
      for (size_t j = 0; j < cols; j++)
      {
        if (!input)
        {
          std::cout << "Bad matrix\n";
          exit(1);
        }
        input >> array[i][j];
      }
    }
    return array;
  }
  catch (const std::bad_alloc & e)
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
  delete matrix;
}

void gladyshev::freeMatrix(int ** matrix, size_t rows, size_t)
{
  gladyshev::freeMatrix(matrix, rows);
}
