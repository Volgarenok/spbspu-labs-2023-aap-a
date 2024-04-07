#include "tasks.hpp"
#include <cstddef>

void poleleyko::spiral_matrix_transformation
(int* matrix, size_t count_of_rows, size_t count_of_cols)
{
  size_t step = 1;
  size_t row = 0;
  size_t col = 0;

  while (row < count_of_rows && col < count_of_cols)
  {
    matrix[row * count_of_cols + col] -= step;
    row++;
    col++;
    for (size_t i = col; i < count_of_cols; i++)
    {
      matrix[row * count_of_cols + i] -= step;
    }
    for (size_t i = row + 1; i < count_of_rows; i++)
    {
      matrix[i * count_of_cols + count_of_cols - 1] -= step;
    }
    if (row < count_of_rows)
    {
      for (size_t i = count_of_cols - 2; i >= col; i--)
      {
        matrix[(count_of_rows - 1) * count_of_cols + i] -= step;
      }
    }
    if (col < count_of_cols)
    {
      for (size_t i = count_of_rows - 2; i > row; i--)
      {
        matrix[i * count_of_cols + col] -= step;
      }
    }
    step++;
  }
}

int poleleyko::count_row_not_same_numbers
(int* matrix, size_t count_of_rows, size_t count_of_cols)
{
  int count = 0;
  for (size_t i = 0; i < count_of_rows; ++i)
  {
    bool has_consecutive_duplicates = false;
    for (size_t j = 1; j < count_of_cols; ++j)
    {
      if (matrix[i * count_of_cols + j] == matrix[i * count_of_cols + j - 1])
      {
        has_consecutive_duplicates = true;
        break;
      }
    }
    if (!has_consecutive_duplicates)
    {
      ++count;
    }
  }
  return count;
}
