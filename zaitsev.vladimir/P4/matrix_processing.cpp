#include "matrix_processing.h"

double zaitsev::smoothMatrixElement(const int* matrix, size_t n_rows, size_t n_cols, size_t row_pos, size_t col_pos)
{
  double res = 0;
  bool is_row_bound = (row_pos == 0 || row_pos == n_rows - 1);
  bool is_col_bound = (col_pos == 0 || col_pos == n_cols - 1);
  size_t l_row_bound = (row_pos > 0 ? row_pos - 1 : 0);
  size_t r_row_bound = (row_pos < n_rows - 1 ? row_pos + 1 : row_pos);
  size_t l_col_bound = (col_pos > 0 ? col_pos - 1 : 0);
  size_t r_col_bound = (col_pos < n_cols - 1 ? col_pos + 1 : col_pos);
  double divider = (3 - is_row_bound) * (3 - is_col_bound) - 1;
  for (size_t i = l_row_bound; i <= r_row_bound; ++i)
  {
    for (size_t j = l_col_bound; j <= r_col_bound; ++j)
    {
      if (i != row_pos || j != col_pos)
      {
        res += matrix[i * n_cols + j] / divider;
      }
    }
  }
  return res;
}

void zaitsev::smoothMatrix(const int* matrix, double* smoothed_matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows; ++i)
  {
    for (size_t j = 0; j < cols; ++j)
    {
      smoothed_matrix[i * cols + j] = smoothMatrixElement(matrix, rows, cols, i, j);
    }
  }
  return;
}
