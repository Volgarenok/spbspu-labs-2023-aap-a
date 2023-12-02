#include "getMinimumSum.hpp"
#include "minSumMdg.hpp"
#include <iostream>
#include <fstream>
#include <cstddef>

int main(int argc, char* argv[])
{
  using namespace spiridonov;

  if (argc != 4)
  {
    std::cerr << "Usage: ./lab num input output" << "\n";
    return 1;
  }

  int num = 0;

  try
  {
    num = std::stoi(argv[1]);
  }

  catch (const std::exception & e)
  {
    std::cerr << "Error first argument" << e.what() << "\n";
    return 1;
  }

  if ((num < 1) || (num > 2))
  {
    std::cerr << "First argument must be 1 or 2" << "\n";
    return 1;
  }

  size_t rows = 0;
  size_t cols = 0;
  std::fstream input(argv[2]);
  std::fstream output(argv[3]);
  input >> rows >> cols;
  size_t min_sum = 0;

  if (!input)
  {
    std::cout << "Failed to open input file: " << argv[2] << "\n";
    return 2;
  }

  if (rows == 0 || cols == 0)
  {
    output << 0 << "\n";
    return 0;
  }

  int * matrix = nullptr;
  int interim_matrix[10000] = {};

  if (num == 1)
  {
    matrix = interim_matrix;
    min_sum = spiridonov::getMinimumSum(matrix, rows, cols);
  }

  else if (num == 2)
  {
    matrix = new int[rows * cols]();
    try
    {
      spiridonov::readMatrix(input, matrix, rows, cols);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Failed to allocate memory for matrix: " << e.what() << "\n";
      delete[] matrix;
      return 2;
    }
    min_sum = spiridonov::getMinimumSum(matrix, rows, cols);
    delete[] matrix;
  }
  else
  {
    std::cout << "Invalid value for num: " << num << "\n";
    return 1;
  }

  if (!output)
  {
    std::cerr << "Failed to open output file: " << argv[3] << "\n";
    return 1;
  }

  output << min_sum << "\n";
  return 0;
}
