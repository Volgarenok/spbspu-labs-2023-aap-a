#include <iostream>
#include <fstream>
#include <cstddef>
#include <cstdlib>
#include <stdexcept>
#include "getMinimumSum.hpp"
#include "readMatrix.hpp"

int main(int argc, char* argv[])
{
  using namespace spiridonov;

  if (argc != 4)
  {
    std::cerr << "Usage: ./lab num input output" << "\n";
    return 1;
  }

  int num = 0;
  char * check = nullptr;

  try
  {
    num = std::strtoll(argv[1], std::addressof(check), 10);
  }

  catch (const std::invalid_argument & e)
  {
    std::cerr << "Error checking first argument" << "\n";
    return 1;
  }

  if (*check != '\0')
  {
    std::cerr << "Invalid first argument" << "\n";
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
