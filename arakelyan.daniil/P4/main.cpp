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
  //проверка кол-ва аргументов передаваем. при вызове программы
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task; name of input file; name of output file\n";
    return 1;
  }

  //проверка первого аргумента
  int firstArgument = 0;
  try
  {
    firstArgument = std::stoll(argv[1]);
  } catch (const std::invalid_argument & e) {
    std::cerr << "Invalid first argument\n";
    return 1;
  }
  if ((firstArgument < 1) || (firstArgument > 2))
  {
    std::cerr << "Number of tusk must be 1 or 2\n";
    return 1;
  }

  //файл ввода
  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cannot open the input file\n";
    return 2;
  }

  //файл вывода
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Cannot open the output file\n";
    return 2;
  }


  if (firstArgument == 1)
  {
    int rows = 0;
    int cols = 0;
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Cannot read input file\n";
      return 2;
    }
    if ((rows * cols == 0) || (rows + cols == 0))
    {
      std::cerr << "Incorrect matrix dimensions\n";
      return 2;
    }

    int matrix[10000] = {};
    double smoothedMatrix[10000] = {};
    try
    {
      ara::inputStatMatrix(input, matrix,rows*cols);
      ara::transformToSmoothMatrix(matrix,smoothedMatrix,rows,cols);
      ara::outputTransformMatrix(output,smoothedMatrix,rows,cols);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Error: " << e.what();
      return 2;
    }
    input.close();
    output.close();
  }
  else if (firstArgument == 2)
  {
    int rows = 0;
    int cols = 0;
    input >> rows;
    input >> cols;
    if (!input)
    {
      std::cerr << "Cannot read input file\n";
      return 2;
    }
    if ((rows * cols == 0) || (rows + cols == 0))
    {
      std::cerr << "Incorrect matrix dimensions\n";
      return 2;
    }

    int * matrix = new int[rows*cols];
    if (!matrix)
    {
      std::cerr << "Can't create matrix\n";
      input.close();
      output.close();
      delete [] matrix;
      return 2;
    }

    double * smoothedMatrix = new double[rows*cols];
    if (!smoothedMatrix)
    {
      std::cerr << "Can't create matrix\n";
      input.close();
      output.close();
      delete [] matrix;
      delete [] smoothedMatrix;
      return 2;
    }
    try 
    {
      ara::inputDynMatrix(input, matrix, rows*cols);
      ara::transformToSmoothMatrix(matrix, smoothedMatrix, rows, cols);
      ara::outputTransformMatrix(output, smoothedMatrix, rows, cols);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << "Error: " << e.what() << "\n";
      delete [] matrix;
      delete [] smoothedMatrix;
      input.close();
      output.close();
      return 2;
    }
    // ara::inputDynMatrix(input, matrix, rows*cols);
    // ara::transformToSmoothMatrix(matrix, smoothedMatrix, rows, cols);
    // ara::outputTransformMatrix(output, smoothedMatrix, rows, cols);
    delete [] matrix;
    delete [] smoothedMatrix;
    output.close();
  }

  return 0;
}
