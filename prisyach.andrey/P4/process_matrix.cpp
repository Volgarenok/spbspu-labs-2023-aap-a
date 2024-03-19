#include "process_matrix.hpp"

#include <iostream>
#include <stdexcept>

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

void prisyach::transformMatrix(int* matrix, size_t rows, size_t cols)
{
  size_t minSide = std::min(rows, cols);
  for (size_t layer = 0; layer < (minSide + 1) / 2; layer++)
  {
    size_t count = 0;
    for (size_t i = layer; i < cols - layer; i++)
    {
      matrix[layer * cols + i] = layer + 2;
      count++;
    }
    for (size_t i = layer + 1; i < rows - layer; i++)
    {
      matrix[i * cols + cols - layer - 1] = layer + 2 + count;
      count++;
    }
    for (size_t i = cols - layer - 2; i >= layer; i--)
    {
      matrix[(rows - layer - 1) * cols + i] = layer + 2 + count;
      count++;
    }
    for (size_t i = rows - layer - 2; i > layer; i--)
    {
      matrix[i * cols + layer] = layer + 2 + count;
      count++;
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
