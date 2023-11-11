#include "circle_fill.hpp"
#include <algorithm>
#include <limits>
#include <stdexcept>

void erohin::statCircleFill(int (&matrix)[10000], const size_t & rows, const size_t & cols)
{
  size_t dist_edge_rows = 0;
  size_t dist_edge_cols = 0;
  size_t add = 0;
  size_t max_size = std::numeric_limits< size_t > ::max();
  for (size_t i = 0; i < rows; ++i)
  {
    dist_edge_rows = std::min(i, rows - i - 1);
    for (size_t j = 0; j < cols; ++j)
    {
      dist_edge_cols = std::min(j, cols - j - 1);
      add = std::min(dist_edge_rows, dist_edge_cols) + 1;
      if (matrix[rows * i + j] > max_size - add)
      {
        throw std::logic_error("Matrix element is too large");
      }
      matrix[rows * i + j] += add;
    }
  }
  return;
}

void erohin::dynCircleFill(int * matrix, const size_t & rows, const size_t & cols)
{
  size_t dist_edge_rows = 0;
  size_t dist_edge_cols = 0;
  size_t add = 0;
  size_t max_size = std::numeric_limits< size_t > ::max();
  for (size_t i = 0; i < rows; ++i)
  {
    dist_edge_rows = std::min(i, rows - i - 1);
    for (size_t j = 0; j < cols; ++j)
    {
      dist_edge_cols = std::min(j, cols - j - 1);
      add = std::min(dist_edge_rows, dist_edge_cols) + 1;
      if (matrix[rows * i + j] > max_size - add)
      {
        throw std::logic_error("Matrix element is too large");
      }
      matrix[rows * i + j] += add;
    }
  }
  return;
}
