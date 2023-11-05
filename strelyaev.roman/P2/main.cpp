#include <iostream>
#include <fstream>
#include <exception>
#include "matrix.h"
#include "checkargs.h"  

int main(int argc, char * argv[])
{
  std::fstream input(argv[2]);

  int n = 0;
  try
  {
    n = std::stoll(argv[1]);
    checkArgs(argc, argv, n, input);
  }
  catch(const std::invalid_argument & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  catch (const std::logic_error & e)
  {
    std::cerr << e.what() << "\n";
    return 2;
  }
  int rows = 0;
  int columns = 0;

  input >> rows;
  input >> columns;
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




