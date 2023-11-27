#include "is_min.hpp"

bool nikitov::isMin(size_t i, const int matrix[], size_t cols)
{
  int num = matrix[i];
  bool isRequiredCondition = false;
  bool& isOk = isRequiredCondition;

  isOk = num < matrix[i - cols - 1];
  isOk = isOk && num < matrix[i - cols - 1];
  isOk = isOk && num < matrix[i - cols];
  isOk = isOk && num < matrix[i - cols + 1];
  isOk = isOk && num < matrix[i - 1];
  isOk = isOk && num < matrix[i + 1];
  isOk = isOk && num < matrix[i + cols - 1];
  isOk = isOk && num < matrix[i + cols];
  isOk = isOk && num < matrix[i + cols + 1];

  return isRequiredCondition;
}
