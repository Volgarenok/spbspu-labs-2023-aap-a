#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
#include <stdexcept>
#include "min_row_array.hpp"
#include "max_col_array.hpp"
#include "input_array.hpp"
#include "get_result.hpp"

int main(int argc, char ** argv)
{
  using namespace namestnikov;
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  int num = 0;
  char * endOfParsing = nullptr;
  try
  {
    num = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
    if ((num != 1) && (num != 2))
    {
      std::cerr << "Wrong number in command line\n";
      return 3;
    }

  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 3;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Cannot parse a value\n";
    return 3;
  }
  if (*endOfParsing != '\0')
  {
    std::cerr << "First number is not correct\n";
    return 1;
  }
  size_t rows = 0, cols = 0;
  size_t count = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Can not read a number\n";
    return 2;
  }
  int array[10000] = {};
  int * matrix = nullptr;
  if (num == 1)
  {
    matrix = array;
  }
  else if (num == 2)
  {
    try
    {
      matrix = new int [rows * cols];
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 3;
    }
  }
  size_t result = inputArray(input, matrix, rows * cols, rows * cols);
  int * minRow = nullptr;
  int * maxCol = nullptr;
  try
  {
    minRow = minRowArray(result, cols, matrix);
    maxCol = maxColArray(result, cols, matrix);
  }
  catch (...)
  {
    delete [] minRow;
    delete [] maxCol;
    if (num == 2)
    {
      delete [] matrix;
    }
    std::cerr << "Not enough memory\n";
    return 3;
  }
  count = getResult(matrix, maxCol, minRow, result, cols);
  if (num == 2)
  {
    delete [] matrix;
  }
  delete [] maxCol;
  delete [] minRow;
  std::ofstream output(argv[3]);
  output << count << "\n";
}
