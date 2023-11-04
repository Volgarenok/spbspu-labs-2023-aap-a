#include <iostream>
#include <fstream>
#include <exception>
#include "matrix.h"
#include "checkargs.h"
#include <algorithm>

void matrixSubtraction(int * original, int * reverse, int n)
{
  for (int i = 0; i < n; i++)
  {
    original[i] -= reverse[i];
  }
}

void printMatrix(int * a, const int amount, const int columns)
{
  for (int i = 0; i < amount; i++)
  {
    std::cout << a[i] << " ";
    if ((i+1) % columns == 0)
    {
      std::cout << "\n";
    }
  }
}

void clockwise(int * a, int rows, int columns)
{
  int start = (rows-1) * columns + 0;
  int num = 1;
  for (int delta = 0; delta < std::max(rows - 2, 1); delta++)
  {
    for (int i = (rows-1)*columns - delta*(columns-1); i > delta*(columns+1); i-=columns)
    {
      a[i] = num++;
    }
    for (int i  = 0 + delta*(columns+1); i < columns + delta*(columns-1); i+=1)
    {
      a[i] = num++;
    }
    --num;
    for (int i  = (columns-1) + delta*(columns-1); i < rows*columns - delta*(columns+1) - 1; i+=columns)
    {
      a[i] = num++;
    }
    for (int i  = rows*columns - 1 - delta*(columns+1); i > (rows-1) * columns - delta*(columns-1); i-=1)
    {
      a[i] = num++;
    }
  }
}

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


  if (n == 1)
  {
    try
    {
      int matrix[rows * columns] = {};
      sMatrix(input, matrix, rows*columns);
      int clock_matrix[rows*columns];
      clockwise(clock_matrix, rows, columns);
      matrixSubtraction(matrix, clock_matrix, rows*columns);
      printMatrix(matrix, rows*columns, columns);
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
      std::cerr << e.what() << "\n";
      return 2;
    }
  }
}

