#include "most_long_sequence.hpp"
#include "find_max_row.hpp"

size_t stepanov::findMostLongSequence(const int *matrix, size_t rows, size_t cols)
{
  size_t maxRow = 0;
  (rows != 0 && cols != 0) ? maxRow = stepanov::findMaxRow(matrix, rows, cols) : maxRow = 0;
  return maxRow;
}
