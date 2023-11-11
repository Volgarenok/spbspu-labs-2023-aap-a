#include "circle_fill.hpp"
#include <algorithm>

void erohin::statCircleFill(int (&matrix)[10000], const size_t & rows, const size_t & cols)
{
  size_t dist_edge_rows = 0;
  size_t dist_edge_cols = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    dist_edge_rows = std::min(i, rows - i - 1);
    for (size_t j = 0; j < cols; ++j)
    {
      dist_edge_cols = std::min(j, cols - j - 1);
      matrix[rows * i + j] += std::min(dist_edge_rows, dist_edge_cols);
    }
  }
  return;
}

void erohin::dynCircleFill(int * matrix, const size_t & rows, const size_t & cols)
{
  size_t dist_edge_rows = 0;
  size_t dist_edge_cols = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    dist_edge_rows = std::min(i, rows - i - 1);
    for (size_t j = 0; j < cols; ++j)
    {
      dist_edge_cols = std::min(j, cols - j - 1);
      matrix[rows * i + j] += std::min(dist_edge_rows, dist_edge_cols);
    }
  }
  return;
}
