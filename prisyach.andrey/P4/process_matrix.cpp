#include "process_matrix.hpp"

#include <iostream>
#include <stdexcept>
#include <cstddef>

size_t prisyach::findMaxSequence(const int * matrix, size_t rows, size_t cols)
{
  size_t max_sequence = 0;
  size_t row_max_sequence = 0;

  for (size_t row = 0; row < rows; ++row)
  {
    size_t current_sequence = 1;
    for (size_t col = 0; col < cols - 1; ++col)
    {
      if (matrix[row * cols + col] == matrix[row * cols + col + 1])
      {
        ++current_sequence;
        if (current_sequence > max_sequence)
        {
          max_sequence = current_sequence;
          row_max_sequence = row;
        }
      }
      else
      {
        current_sequence = 1;
      }
    }
  }
  return row_max_sequence;
}

void increaseValues(int * matrix, size_t rows, size_t cols)
{
  size_t layer = 1;
  size_t maxLayer = std::min(rows, cols) / 2 + std::min(rows, cols) % 2;
  size_t minDimension = std::min(rows, cols);

  for(size_t layer = 0; layer < maxLayer; layer++)
  {
    for(size_t i = layer; i < cols - layer; i++)
    {
      matrix[layer * cols + i] = layer + 1;
      matrix[(rows - 1 - layer) * cols + i] = layer + 1;
    }

    for(size_t i = layer; i < rows - layer; i++)
    {
      matrix[i * cols + layer] = layer + 1;
      matrix[i * cols + (cols - 1 - layer)] = layer + 1;
    }
  }
}

void prisyach::outputMatrix(std::ostream & input, int * matrix, size_t rows, size_t cols)
{
  for(size_t i = 0; i < rows * cols; ++i)
  {
    input << matrix[i];
    if(!input)
    {
      throw std::runtime_error("Error output matrix elements");
    }
  }
}

void prisyach::readMatrix(std::istream & input, int * matrix, size_t rows, size_t cols)
{
  for (size_t row = 0; row < rows; ++row)
  {
    for (size_t col = 0; col < cols; ++col)
    {
      if(!(input >> matrix[row * cols + col]))
      {
        throw std::runtime_error("Error reading matrix elements");
      }
    }
  }
}
