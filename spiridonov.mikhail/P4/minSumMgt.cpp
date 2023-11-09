#include "getMinimumSum.hpp"
#include "minSumMgt.hpp"

void spiridonov::readMatrix(std::ifstream& input, int* matrix, int size)
{
  for (int i = 0; i < size; i++)
  {
    input >> matrix[i];
  }
}

int spiridonov::getMinimumSum(int * matrix, int rows, int cols)
{
  int min_sum = matrix[cols - 1];

  for (int i = 1; i < rows; i++)
  {
    int sum = matrix[i * cols + cols - 1];

    for (int j = 0; j < cols && i + j < rows; j++)
    {
      sum += matrix[(i + j) * cols + cols - 1 - j];
    }

    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }

  for (int i = 1; i < cols - 1; i++)
  {
    int sum = matrix[i + (cols - 1) * cols];

    for (int j = 0; j < rows && i + j < cols; j++)
    {
      sum += matrix[(rows - 1 - j) * cols + i + j];
    }

    if (sum < min_sum)
    {
      min_sum = sum;
    }
  }

  return min_sum;
}
