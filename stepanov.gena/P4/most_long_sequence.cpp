#include "most_long_sequence.hpp"

size_t stepanov::findMostLongSequence(const int matrix[], size_t rows, size_t cols)
{
  size_t maxRow = 0;
  size_t maxLength = 0;
  if (rows != 0 && cols != 0)
  {
    for (size_t i = 0; i < rows; ++i)
    {
      size_t currentLength = 1;

      for (size_t j = 1; j < cols; ++j)
      {
        size_t index = i * cols + j;
        if (matrix[index] == matrix[index - 1])
        {
          currentLength++;
        }
        else
        {
          currentLength = 1;
        }

        if (currentLength > maxLength)
        {
          maxLength = currentLength;
          maxRow = i + 1;
        }
      }
    }
  }
  else
  {
    maxRow = 0;
  }
  return maxRow;
}
