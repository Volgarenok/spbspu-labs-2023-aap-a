#include <iostream>
#include <string>
#include <fstream>
#include "matrix.hpp"
#include "localMax.hpp"

int main(int argc, char * argv[])
{
  if (argc < 4)
  {
    std::cout << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cout << "Too many arguments\n";
    return 1;
  }
  int numOfTask = 0;
  try
  {
    numOfTask = std::stoi(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "Cannot parse a value\n";
    return 1;
  }
  if ((numOfTask != 1) && (numOfTask != 2))
  {
    std::cerr << "Error number of task";
    return 1;
  }
  using namespace sivkov;
  size_t rows = 1, cols = 1;
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cannot open file!\n";
    return 2;
  }
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read numbers!\n";
    return 2;
  }
  if (rows == 0 && cols == 0)
  {
    return 0;
  }
  int FixedLenMatrix[10000] = {};
  int* dynamicMatrix = nullptr;
  int* matrix = nullptr;

  if (numOfTask == 1)
  {
    matrix = FixedLenMatrix;
  }
  else
  {
    try
    {
      dynamicMatrix = new int[rows * cols];
      matrix = dynamicMatrix;
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error with array\n";
      return 2;
    }
  }
  size_t count = 0;
  try
  {
    fillMatrix(input, matrix, rows * cols);
    count = findLocalMax(matrix, rows, cols);
  }
  catch (const std::logic_error&)
  {
    std::cerr << "Error data or array\n";
    if (numOfTask == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  std::ofstream output(argv[3]);
  output << count << '\n';

  if (numOfTask == 2)
  {
    delete[] matrix;
  }
  return 0;
}
