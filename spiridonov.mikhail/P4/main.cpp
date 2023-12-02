#include "getMinimumSum.hpp"
#include "minSumMdg.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>

int main(int argc, char* argv[])
{
  using namespace spiridonov;

  if (argc != 4)
  {
    std::cerr << "Usage: ./lab num input output" << "\n";
    return 1;
  }

  int num = 0;

  if ((std::atoi(argv[1]) == 1) || (std::atoi(argv[1]) == 2))
  {
    char * arg = argv[1];
    int length = 0;

    while (arg[length] != '\0')
    {
      length++;
    }

    if (length > 1)
    {
      std::cerr << "Invalid first argument" << "\n";
      return 1;
    }
  }

  try
  {
    num = std::atoi(argv[1]);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Error parsing first argument: " << e.what() << "\n";
    return 1;
  }

  if (num < 1 || num > 2)
  {
    std::cerr << "First argument must be 1 or 2" << "\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  size_t rows = 0;
  size_t cols = 0;

  input >> rows >> cols;

  if (!input)
  {
    std::cerr << "Failed to open input file: " << argv[2] << "\n";
    return 2;
  }

  if (rows == 0 || cols == 0)
  {
    output << 0 << "\n";
    output.close();
    return 0;
  }

  int* matrix = nullptr;
  int interim_matrix[10000] = {};

  if (num == 1)
  {
    matrix = interim_matrix;
  }

  if (num == 2)
  {
    matrix = new int[rows * cols];
  }

  try
  {
    spiridonov::readMatrix(input, matrix, rows, cols);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << "Failed to allocate memory for matrix: " << e.what() << "\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }

  size_t min_sum = spiridonov::getMinimumSum(matrix, rows, cols);

  if (num == 2)
  {
    delete[] matrix;
  }

  if (!output)
  {
    std::cerr << "Failed to open output file: " << argv[3] << "\n";
    return 1;
  }

  output << min_sum << "\n";
  return 0;
}
