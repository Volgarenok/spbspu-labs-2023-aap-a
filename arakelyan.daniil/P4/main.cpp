#include <iostream>
#include <fstream>
#include <cstddef>
#include <stdexcept>
#include "input_output_matrix.hpp"
#include "matrix_operations.hpp"

int main (int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task; name of input file; name of output file\n";
    return 1;
  }

  char * endOfParsing = nullptr;
  int firstArgument = std::strtoll(argv[1], std::addressof(endOfParsing), 10);
  if (*endOfParsing != '\0')
  {
    std::cerr << "Invalid first value.\n";
    return 1;
  }

  if ((firstArgument < 1) || (firstArgument > 2))
  {
    std::cerr << "Number of tusk must be 1 or 2\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cannot open the input file\n";
    return 2;
  }

  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Cannot open the output file\n";
    return 2;
  }

  size_t rows = 0;
  size_t cols = 0;

  if (!(input >> rows) || !(input >> cols))
  {
    std::cerr << "Cannot read rows and columns of matrix\n";
    return 2;
  }
  if (rows == 0 && cols == 0)
  {
    std::cout << "Rows: 0; Cols: 0\n";
    return 0;
  }
  if (rows * cols == 0)
  {
    std::cerr << "Incorrect matrix dimensions\n";
    return 2;
  }

  int tempMatrix[10000] = {};
  double tempSmoothedMatrix[10000] = {};

  int * matrix = nullptr;
  double * smoothedMatrix = nullptr;

  if (firstArgument == 1)
  {
    matrix = tempMatrix;
    smoothedMatrix = tempSmoothedMatrix;
  }
  else
  {
    try
    {
      matrix = new int[rows * cols];
      smoothedMatrix = new double[rows * cols];
    }
    catch (const std::bad_alloc & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      delete [] matrix;
      delete [] smoothedMatrix;
      return 2;
    }
  }

  try
  {
    arakelyan::inputMatrix(input, matrix, rows * cols);
    arakelyan::smoothedMatrixCreation(matrix, smoothedMatrix, rows, cols);
    arakelyan::outputMatrix(output, smoothedMatrix, rows, cols);
  }
  catch (const std::logic_error & e)
  {
    std::cerr << "Error: " << e.what() << "\n";
    if (firstArgument == 2)
    {
      delete [] matrix;
      delete [] smoothedMatrix;
    }
    return 2;
  }
  if (firstArgument == 2)
  {
    delete [] matrix;
    delete [] smoothedMatrix;
  }
  return 0;
}
