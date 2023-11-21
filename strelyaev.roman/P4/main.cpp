#include <iostream>
#include <fstream>
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

  int n = 0;
  try
  {
    n = std::stoll(argv[1]);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << "Unable to parse 1st argument" << "\n";
    return 1;
  }

  if ((n < 1) || (n > 2))
  {
    std::cerr << "1st argument must be 1-2 number" << "\n";
    return 1;
  }
    try 
    {
      if (n == 1)
      {
        int matrix[rows * columns] = {};
        int clock_matrix[rows*columns];    
      }
      else
      {
        int * matrix = new int [rows*columns];
        int * clock_matrix = new int [rows*columns];
        inputMatrix(input, matrix, rows*columns);
        makeClockwise(clock_matrix, rows, columns);
        subtractMatrix(matrix, clock_matrix, rows*columns);
        printMatrix(output, matrix, columns*rows);
        delete [] matrix;
        delete [] clock_matrix;
      }
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what();
      return 2;
    }
  /*if (n == 1)
  {
    try
    {
      int matrix[rows * columns] = {};
      int clock_matrix[rows*columns];

    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
  else if (n == 2)
  {
    try
    {
      int * matrix = new int [rows*columns];
      int clock_matrix[rows*columns];
      inputMatrix(input, matrix, rows*columns);
      makeClockwise(clock_matrix, rows, columns);
      subtractMatrix(matrix, clock_matrix, rows*columns);
      printMatrix(output, matrix, columns*rows);
      delete [] matrix;
    }
    catch(const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }*/
}
