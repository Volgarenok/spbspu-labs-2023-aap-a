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
  if (num == 1)
  {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Can not read a number\n";
      return 2;
    }
    int matrix[10000] = {};
    for (size_t i = 0; i < rows * cols; ++i)
    {
      input >> matrix[i];
      if (!input)
      {
        std::cerr << "Can not read a number\n";
        return 2;
      }
    }
    std::ofstream output(argv[3]);
    int * minRow = minRowArray(rows * cols, cols, matrix);
    int * maxCol = maxColArray(rows * cols, cols, matrix);
    size_t count = getResult(matrix, maxCol, minRow, rows * cols, cols);
    output << count << "\n";
    delete [] minRow;
    delete [] maxCol;
  }
  else if (num == 2)
  {
    size_t rows = 0;
    size_t cols = 0;
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    int * matrix = new int [rows * cols];

    size_t result = inputArray(input, matrix, rows * cols, rows * cols);
    if (!input)
    {
      std::cerr << "Can not read numbers\n";
      delete [] matrix;
      return 2;
    }
    std::ofstream output(argv[3]);
    int * minRow = minRowArray(rows * cols, cols, matrix);
    int * maxCol = maxColArray(rows * cols, cols, matrix);
    size_t count = getResult(matrix, maxCol, minRow, result, cols);
    output << count << "\n";
    delete [] matrix;
    delete [] minRow;
    delete [] maxCol;
  }
}
