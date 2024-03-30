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

  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
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
  int fixedMatrix[10000] = {};
  int* matrix = nullptr;

  try
  {
    if (num == 1)
    {
      matrix = new int[sizeOfArray];
    }
    else if (num == 2)
    {
      matrix = fixedMatrix;
    }

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
  }
  catch (const std::exception& e)
  {
    if (num == 1)
    {
      delete[] matrix;
    }
    std::cerr << e.what() << '\n';
    return 1;
  }
  if (num == 1)
  {
    delete[] matrix;
  }
  return 0;
}
