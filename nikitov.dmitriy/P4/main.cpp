#include <iostream>
#include <fstream>
#include <cstring>
#include "input_array.hpp"
#include "count_local_min.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Wrong command line input\n";
    return 1;
  }

  int type = 0;
  char* endOfParsing = nullptr;

  try
  {
    type = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
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

  if (*endOfParsing != '\0')
  {
    std::cerr << "Error: Wrong first argument\n";
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

  int array[10000] = {};
  int* matrix = nullptr;
  if (type == 1)
  {
     matrix = array;
  }
  else if (type == 2)
  {
    try
    {
      matrix = new int [rows * cols];
    }
    catch (const std::bad_alloc&)
    {
      std::cerr << "Error: not enough memory\n";
      return 3;
    }
  }
  else
  {
    std::cerr << "Error: First number doesn't match\n";
    return 1;
  }

  size_t status = inputArray(input, matrix, rows, cols);
  if (status != rows * cols)
  {
    std::cerr << "Error: Wrong element at position: " << status << '\n';
    if (type == 2)
    {
      delete [] matrix;
    }
    return 2;
  }

  count = countLocalMin(matrix, rows, cols);

  if (type == 2)
  {
    delete [] matrix;
  }

  std::ofstream output(argv[3]);
  output << count << '\n';

  return 0;
}
