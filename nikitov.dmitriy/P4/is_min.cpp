#include "is_min.hpp"

bool nikitov::isMin(size_t i, const int matrix[], size_t cols)
{
  int num = matrix[i];
  bool isLessThanNeighbors = false;
  bool& isLTN = isLessThanNeighbors;

  isLTN = num < matrix[i - cols - 1];
  isLTN = isLTN && num < matrix[i - cols - 1];
  isLTN = isLTN && num < matrix[i - cols];
  isLTN = isLTN && num < matrix[i - cols + 1];
  isLTN = isLTN && num < matrix[i - 1];
  isLTN = isLTN && num < matrix[i + 1];
  isLTN = isLTN && num < matrix[i + cols - 1];
  isLTN = isLTN && num < matrix[i + cols];
  isLTN = isLTN && num < matrix[i + cols + 1];

  return isLessThanNeighbors;
}
