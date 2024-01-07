#include "countNonZeroDiagonals.hpp"
#include "incrementCirclesInMatrix.hpp"
#include "readMatrix.hpp"
#include "writeMatrix.hpp"

#include <cstddef>
#include <cstring>
#include <fstream>
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[])
{
  using namespace chernov;
  int num = 0;

  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }

  try
  {
    num = std::atoi(argv[1]);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }

  if (num != 1 && num != 2)
  {
    std::cerr << "No such task\n";
    return 1;
  }

  size_t rows = 0;
  size_t cols = 0;

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  input >> rows >> cols;

  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 1;
  }

  size_t sizeOfArray = rows * cols;

  if (num == 1)
  {
    int* matrix = new int[sizeOfArray];
    try
    {
      readMatrix(input, matrix, rows, cols);
      int result = countNonZeroDiagonals(matrix, rows, cols);
      incrementCirclesInMatrix(matrix, rows, cols);
      std::ofstream output(argv[3]);
      writeMatrix(output, matrix, rows, cols);
      output << '\n' << result;
      if (!output)
      {
        throw std::invalid_argument("Error of output result");
      }
      delete[] matrix;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      delete[] matrix;
      return 1;
    }
  }
  else if (num == 2)
  {
    int matrix[10000] = {};
    try
    {
      readMatrix(input, matrix, rows, cols);
      incrementCirclesInMatrix(matrix, rows, cols);
      std::ofstream output(argv[3]);
      writeMatrix(output, matrix, rows, cols);
      int result = countNonZeroDiagonals(matrix, rows, cols);
      output << '\n' << result;
    }
    catch (const std::exception& e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }
  }
  return 0;
}
