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

  if ((n < 1) || (n > 2) || (position < sizeof(argv[1])))
  {
    std::cerr << "1st argument must be 1-2 number" << "\n";
    return 1;
  }

  if (rows == 0 || columns == 0)
  {
    return 0;
  }

  if (n == 1)
  {
      int matrix[10000];
      int clock_matrix[rows*columns];
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
      return 2;
    }
  }
  if (n == 2)
  {
    int * matrix = new int [10000];
    int * clock_matrix = new int [rows*columns];
    try
    {
      inputMatrix(input, matrix, rows*columns);
      makeClockwise(clock_matrix, rows, columns);
      subtractMatrix(matrix, clock_matrix, rows*columns);
      printMatrix(output, matrix, columns*rows);
    }
    catch(const std::logic_error& e)
    {
      delete [] matrix;
      delete [] clock_matrix;
      std::cerr << e.what() << "\n";
      return 2;
    }
    delete [] matrix;
    delete [] clock_matrix;
  }
}
