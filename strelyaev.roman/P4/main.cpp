#include <iostream>
#include <fstream>
#include <cstddef>
#include <exception>
#include "matrix.h"
#include "clock_matrix.h"
int main(int argc, char * argv[])
{
  using namespace strelyaev;
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task, input_file, output_file\n";
    return 1;
  }
  std::fstream output(argv[3]);
  std::fstream input(argv[2]);
  size_t rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Unable to read input file\n";
    return 2;
  }
  int n = 0;
  char * parsing_position = nullptr;
  try
  {
    n = std::strtoll(argv[1], std::addressof(parsing_position), 10);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Unable to parse 1st argument\n";
    return 1;
  }
  if (*parsing_position != '\0')
  {
    std::cerr << "Invalid first argument\n";
    return 1;
  }

  if ((n < 1) || (n > 2))
  {
    std::cerr << "First argument out of range\n";
    return 1;
  }

  if ((rows == 0) || (columns == 0))
  {
    return 0;
  }

  int * matrix = nullptr;
  int * temp_pointer_origin = nullptr;
  int * temp_pointer_clock = nullptr;
  int * clock_matrix = nullptr;
  int temp_matrix[10000] = {};
  int temp_clock[10000] = {};
  if (n == 1)
  {
    matrix = temp_matrix;
    clock_matrix = temp_clock;
  }
  if (n == 2)
  {
    try
    {
      matrix = new int [rows * columns];
      clock_matrix = new int [rows * columns];
      temp_pointer_origin = matrix;
      temp_pointer_clock = clock_matrix;
    }
    catch (...)
    {
      delete [] matrix;
      delete [] clock_matrix;
      return 2;
    }
  }

  try
  {
    inputMatrix(input, matrix, rows * columns);
    makeClockwise(clock_matrix, rows, columns);
    subtractMatrix(matrix, clock_matrix, rows * columns);
    printMatrix(output, matrix, columns * rows) << "\n";
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    delete [] temp_pointer_origin;
    delete [] temp_pointer_clock;
    return 2;
  }
  delete [] temp_pointer_origin;
  delete [] temp_pointer_clock;
}
