#include <iostream>
#include <fstream>
#include <exception>
#include "matrix.h"
#include "clock_matrix.h"

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task, input_file, output_file" << "\n";
    return 1;
  }
  int rows = 0;
  int columns = 0;

  std::fstream input(argv[2]);
  input >> rows;
  input >> columns;
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
    std::cerr << "Unable to perse 1st argument" << "\n";
    return 1;
  }

  if ((n < 1) || (n > 2))
  {
    std::cerr << "1st argument must be 1-2 number" << "\n";
    return 1;
  }

  std::fstream output(argv[3]);

  if (n == 1)
  {
    try
    {
      int matrix[rows * columns] = {};
      sMatrix(input, matrix, rows*columns);
      int clock_matrix[rows*columns];
      clockwise(clock_matrix, rows, columns);
      matrixSubtraction(matrix, clock_matrix, rows*columns);
      for (int i = 0; i < columns*rows; i++)
      {
        output << matrix[i] << " ";
      }
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
      int * matrix = new int[rows*columns];
      dMatrix (input, matrix, rows*columns);
      int clock_matrix[rows*columns];
      clockwise(clock_matrix, rows, columns);
      matrixSubtraction(matrix, clock_matrix, rows*columns);
      for (int i = 0; i < columns*rows; i++)
      {
        output << matrix[i] << " ";
      }
      delete [] matrix;
    }
    catch(const std::logic_error& e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
}
