#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include "min_row_array.hpp"
#include "max_col_array.hpp"
#include "input_array.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
    if ((num != 1) && (num != 2))
    {
      std::cerr << "Wrong number in command line\n";
      return 3;
    }

  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }
  if (num == 1)
  {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Can not read a number\n";
      return 2;
    }
    int matrix[10000];
    for (size_t i = 0; i < rows * cols; ++i)
    {
      input >> matrix[i];
      if (!input)
      {
        std::cerr << "Can not read a number\n";
        return 2;
      }
    }
    std::ofstream output(argv[3]);
    int * minRow = minRowArray(rows * cols, cols, matrix);
    int * maxCol = maxColArray(rows * cols, cols, matrix);
    size_t count = 0;
    for (size_t i = 0; i < rows * cols; i = i + cols)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if ((matrix[i + j] == minRow[i]) && (matrix[i + j] == maxCol[j]))
        {
          ++count;
        }
      }
    }
    output << count << "\n";
  }
  else if (num == 2)
  {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int * matrix = new int [rows*cols];
    size_t result = inputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Can not read numbers\n";
      delete [] matrix;
      return 2;
    }
    std::ofstream output(argv[3]);
    int * minRow = minRowArray(result, cols, matrix);
    int * maxCol = maxColArray(result, cols, matrix);
    size_t count = 0;
    for (size_t i = 0; i < result; i = i + cols)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if ((matrix[i + j] == minRow[i]) && (matrix[i + j] == maxCol[j]))
        {
          ++count;
        }
      }
    }
    output << count << "\n";
    if (matrix != nullptr)
    {
      delete [] matrix;
    }
  }
}
