#include <iostream>
#include <fstream>
#include "getMinimumSum.hpp"
#include "minSumMgt.hpp"

int main(int argc, char * argv[])
{
  using namespace spiridonov;
  if (argc != 4)
  {
    std::cerr << "Usage: ./lab num input output" << "\n";
    return 1;
  }

  int num = std::atoi(argv[1]);
  std::ifstream input(argv[2]);

  if (!input)
  {
    std::cout << "Failed to open input file: " << argv[2] << "\n";
    return 2;
  }
  int rows = 0;
  int cols = 0;
  input >> rows >> cols;

  num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Error parsing first argument" << "\n";
    return 1;
  }

  if ((num < 1) || (num > 2))
  {
    std::cerr << "First argument must be 1 or 2" << "\n";
    return 1;
  }

  int* matrix;
  if (num == 1)
  {
    int static_matrix[rows * cols];
    matrix = static_matrix;
  }
  else if (num == 2)
  {
    try
    {
      matrix = new int[rows * cols];
    }
    catch (std::bad_alloc & e)
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
  catch (std::ifstream::failure & e)
  {
    std::cerr << "Failed to read input from file: " << e.what() << "\n";
    return 2;
  }
}
