#include "getMinimumSum.hpp"
#include "minSumMdg.hpp"
#include <iostream>
#include <fstream>
#include <string>

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
  catch (const std::exception &)
  {
    std::cerr << "Error parsing first argument" << "\n";
    return 1;
  }

  if ((num < 1) || (num > 2))
  {
    std::cerr << "First argument must be 1 or 2" << "\n";
    return 1;
  }

  unsigned int rows = 0;
  unsigned int cols = 0;
  std::ifstream input(argv[2]);
  std::ofstream output(argv[3]);
  input >> rows >> cols;
  int min_sum = 0;

  if (rows == 0 || cols == 0)
  {
    output << 0 << "\n";
    output.close();
    return 0;
  }

  if (!input)
  {
    std::cout << "Failed to open input file: " << argv[2] << "\n";
    return 2;
  }

  if (num == 1)
  {
   int matrix[rows * cols] = {0};
    try
    {
      spiridonov::readMatrix(input, matrix, rows, cols);
    }
    catch (const std::logic_error &)
    {
      std::cerr << "Failed to allocate memory for matrix: " << "\n";
      return 2;
    }
    min_sum = spiridonov::getMinimumSum(matrix, rows, cols);
  }

  else if (num == 2)
  {
    int * matrix = new int[rows * cols]();
    try
    {
      spiridonov::readMatrix(input, matrix, rows, cols);
    }
    catch (const std::logic_error &)
    {
      std::cerr << "Failed to allocate memory for matrix: " << "\n";
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

  input.close();

  if (!output)
  {
    std::cerr << "Failed to open output file: " << argv[3] << "\n";
    return 1;
  }

  output << min_sum << "\n";
  output.close();
  return 0;
}
