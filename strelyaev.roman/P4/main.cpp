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
    std::cerr << "Must be 3 arguments: task, input_file, output_file" << "\n";
    return 1;
  }
  std::fstream output(argv[3]);
  std::fstream input(argv[2]);
  size_t rows = 0, columns = 0;
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Unable to read input file" << "\n";
    return 2;
  }
  size_t position = 0;
  int n = 0;
  try
  {
    n = std::stoll(argv[1], &position);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Unable to parse 1st argument" << "\n";
    return 1;
  }

  int i = 0;
  for (i; argv[1][i] != '\0'; i++);
  if ((i != 1))
  {
    std::cerr << "1st argument must be 1-2 number" << "\n";
    return 1;
  }

  if (rows == 0 || columns == 0)
  {
    return 0;
  }
  int * matrix = nullptr;
  int * clock_matrix = nullptr;
  int temp_matrix[10000];
  int temp_clock[columns*rows];
  if (n == 1)
  {
    matrix = temp_matrix;
    clock_matrix = temp_clock;
  }
  if (n == 2)
  {
    try
    {
    matrix = new int [10000];
    clock_matrix = new int [rows*columns];
    }
    catch(...)
    {
      delete [] matrix;
      delete [] clock_matrix;
      return 2;
    }
  }

  try
  {
  inputMatrix(input, matrix, rows*columns);
  makeClockwise(clock_matrix, rows, columns);
  subtractMatrix(matrix, clock_matrix, rows*columns);
  printMatrix(output, matrix, columns*rows);
  }
  catch (const std::logic_error& e)
  {
    std::cerr << e.what() << "\n";
    if (n == 2)
    {
      delete [] matrix;
      delete [] clock_matrix;
    }
    return 2;
  }

  if (n == 2)
  {
    delete [] matrix;
    delete [] clock_matrix;
  }
}
