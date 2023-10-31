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
  int start_position = (rows-1) * columns + 0;
  if (n == 1)
  {
    try 
    {
      int matrix[rows * columns] = {};
      sMatrix(input, matrix, rows*columns); 
      Clockwise(matrix, rows*columns, start_position, columns, 1);
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
      delete [] matrix;
    }
    catch(const std::logic_error& e)
    {
      std::cerr << e.what() << '\n';
      return 2;
    }
  } 
}
