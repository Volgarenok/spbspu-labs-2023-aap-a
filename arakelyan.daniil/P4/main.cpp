#include <cstddef>
#include <iomanip>
#include <iostream>
#include <stdexcept>
#include <string>
#include "input_output_matrix.hpp"
#include "matrix_operations.hpp"
#include <stdexcept>



int main (int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task; name of input file; name of output file\n";
    return 1;
  }

  int firstArgument = 0;
  try
  {
    firstArgument = std::stoll(argv[1]);
  }
  catch (const std::invalid_argument & e)
  {
    std::cerr << "Invalid first argument\n";
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


  if (firstArgument == 1)
  {
    size_t rows = 0;
    size_t cols = 0;

    if (!(input >> rows) || !(input >> cols))
    {
      std::cerr << "Cannot read input file\n";
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

    int matrix[10000] = {};
    double smoothedMatrix[10000] = {};
    try
    {
      arakelyan::inputMatrix(input, matrix, rows*cols);
      arakelyan::transformToSmoothMatrix(matrix, smoothedMatrix, rows,cols);
      arakelyan::outputTransformMatrix(output, smoothedMatrix, rows, cols);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Error: " << e.what();
      return 2;
    }
  }
  else if (firstArgument == 2)
  {
    size_t rows = 0;
    size_t cols = 0;

    if (!(input >> rows) || !(input >> cols))
    {
      std::cerr << "Cannot read input file\n";
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

    int * matrix = new int[rows*cols];
    if (!matrix)
    {
      std::cerr << "Can't create matrix 1\n";
      delete [] matrix;
      return 2;
    }

    double * smoothedMatrix = new double[rows*cols];
    if (!smoothedMatrix)
    {
      std::cerr << "Can't create matrix 2\n";
      delete [] matrix;
      delete [] smoothedMatrix;
      return 2;
    }
    try
    {
      arakelyan::inputMatrix(input, matrix, rows*cols);
      arakelyan::transformToSmoothMatrix(matrix, smoothedMatrix, rows, cols);
      arakelyan::outputTransformMatrix(output, smoothedMatrix, rows, cols);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      delete [] matrix;
      delete [] smoothedMatrix;
      return 2;
    }
    delete [] matrix;
    delete [] smoothedMatrix;
  }

  return 0;
}
