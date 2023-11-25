#include <iostream>
#include <fstream>
#include <cstring>
#include "input_array.hpp"
#include "start_counter.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Wrong command line input\n";
    return 1;
  }

  if (strlen(argv[1]) != 1)
  {
    std::cerr << "Error: Wrong first argument\n";
  }

  int type = 0;
  try
  {
    type = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Error: First argument is out of range\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Error: First argument is not a number\n";
    return 1;
  }

  using namespace nikitov;

  size_t rows = 0, cols = 0;
  size_t count = 0;

  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Error: Wrong rows or cols input\n";
    return 2;
  }
  if (type == 1)
  {
    int matrix[10000] = {};

    size_t status = inputArray(input, matrix, rows, cols);
    if (status != rows * cols)
    {
      std::cerr << "Error: Wrong element at position: " << status << '\n';
      return 2;
    }

    startCounter(matrix, rows, cols, count);
  }
  else if (type == 2)
  {
    int* matrix = nullptr;
    try
    {
      matrix = new int [rows * cols];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error: not enough memory\n";
      return 3;
    }

    size_t status = inputArray(input, matrix, rows, cols);
    if (status != rows * cols)
    {
        delete [] matrix;
        std::cerr << "Error: Wrong element at position: " << status << '\n';
        return 2;
    }

    startCounter(matrix, rows, cols, count);
    delete [] matrix;
  }
  else
  {
    std::cerr << "Error: First number doesn't match\n";
    return 1;
  }

  std::ofstream output(argv[3]);
  output << count << '\n';

  return 0;
}
