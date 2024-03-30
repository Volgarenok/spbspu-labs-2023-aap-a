#include "is_min.hpp"

bool stepanov::findMin(const int *matrix, size_t index, size_t cols)
{
  size_t i = index;
  size_t c = cols;
  const int *n = matrix + i;
  bool isLess = ((*n) < *(n - c));
  isLess = isLess && ((*n) < *(n - c));
  isLess = isLess && ((*n) < *(n + c));
  isLess = isLess && ((*n) < *(n - 1));
  isLess = isLess && ((*n) < *(n + 1));
  isLess = isLess && ((*n) < *(n - c - 1));
  isLess = isLess && ((*n) < *(n - c + 1));
  isLess = isLess && ((*n) < *(n + c - 1));
  isLess = isLess && ((*n) < *(n + c + 1));

  return isLess;
}

