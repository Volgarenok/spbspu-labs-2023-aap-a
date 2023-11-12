#include <cstddef>
#include <iomanip>
#include <iostream>
#include <string>
#include "input_matrix.hpp"
#include "matrix_transform.hpp"



int main (int argc, char * argv[])
{
  //проверка кол-ва аргументов передаваем. при вызове программы
  if (argc != 4)
  {
    std::cerr << "Must be 3 arguments: task; name of input file; name of output file\n";
    return 1;
  }

  //проверка первого аргумента
  char * endOfParse = nullptr;
  long firstArgument = std::strtoll(argv[1],&endOfParse,10);
  if (firstArgument == 0 && endOfParse == argv[1])
  {
    std::cerr << "Cannot parse the first argument!\n";
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

  int rows = 0;
  int cols = 0;
  input >> rows;
  input >> cols;
  if (!input)
  {
    std::cerr << "Cannot read input file\n";
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
    int matrix[10000] = {};
    double smoothed[10000] = {};
    ara::inputStatMatrix(input, matrix,rows*cols);
    ara::transformToSmoothMatrix(matrix,smoothed,rows,cols);
    for (size_t i = 0; i < rows; ++i)
    {
      output << "| ";
      for(size_t j = 0; j < cols; ++j)
      {
        output << std::fixed << std::setprecision(1) << " " <<
          smoothed[i * cols + j];
      }
      output << " |\n";
    }
  }
  else
  {
    int * matrix = new int[rows*cols];
    double * smoothedMatrix = new double[rows*cols];
    ara::inputDynMatrix(input, matrix, rows*cols);
    ara::transformToSmoothMatrix(matrix, smoothedMatrix, rows, cols);
    for (size_t i = 0; i < rows; ++i)
    {
      output << "| ";
      for(size_t j = 0; j < cols; ++j)
      {
        output << std::fixed << std::setprecision(1) << " " <<
          smoothedMatrix[i * cols + j];
      }
      output << " |\n";
    }
    delete [] matrix;
  }
  input.close();
  return 0;
}
