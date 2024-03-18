#include "numrow_check.hpp"

unsigned int ishmuratov::checkRow(const int * matrix, size_t rows, size_t cols)
{
  size_t max_seq = 0;
  unsigned int row_num = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    size_t cur_seq = 1;
    for (size_t j = 0; j < cols - 1; ++j)
    {
      if (matrix[i * cols + j] == matrix[i * cols + j + 1])
      {
        cur_seq += 1;
      }
    }
    if (cur_seq > max_seq)
    {
      max_seq = cur_seq;
      row_num = i + 1;
    }
  }
  return row_num;
}
