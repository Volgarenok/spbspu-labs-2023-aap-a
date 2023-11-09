#include "getMinimumSum.hpp"
#include "minSumMgt.hpp"
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
    num = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << "Error parsing first argument" << "\n";
    return 1;
  }

  if ((num < 1) || (num > 2))
  {
    std::cerr << "First argument must be 1 or 2" << "\n";
    return 1;
  }

  int rows = 0, cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;

  if (!input)
  {
    std::cout << "Failed to open input file: " << argv[2] << "\n";
    return 2;
  }

  int* matrix;
  if (num == 1)
  {
    try
    {
      int* static_matrix = new int[rows * cols]();
      matrix = static_matrix;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }

  else if (num == 2)
  {
    try
    {
      matrix = new int[rows * cols];
      delete[] matrix;
    }
    catch (const std::logic_error& e)
    {
      std::cerr << "Failed to allocate memory for matrix: " << e.what() << "\n";
      return 2;
    }
  }

  else
  {
    std::cout << "Invalid value for num: " << num << "\n";
    return 1;
  }
  try
  {
    for (int i = 0; i < rows * cols; i++)
    {
      input >> matrix[i];
    }
  }
  catch (const std::ifstream::failure& e)
  {
    std::cerr << "Failed to read input from file: " << e.what() << "\n";
    return 2;
  }

  spiridonov::readMatrix(input, matrix, rows * cols);
  input.close();
  std::ofstream output(argv[3]);

  if (!output)
  {
    std::cerr << "Failed to open output file: " << argv[3] << "\n";
    delete[] matrix;
    return 1;
  }

  output << spiridonov::getMinimumSum(matrix, rows, cols) << "\n";
  output.close();

  if (num == 2)
  {
    delete[] matrix;
  }
  return 0;
}
