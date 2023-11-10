#include <cstddef>
#include <fstream>
#include <iomanip>
#include <iostream>
#include <stdexcept>
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

  size_t rows = 0;
  size_t cols = 0;
  input >> rows;
  input >> cols;
  if (!input)
  {
    std::cerr << "Cannot read input file\n";
    return 2;
  }
  size_t curSize = rows*cols;
  
  //файл вывода
  std::ofstream output(argv[3]);
  if (!output.is_open())
  {
    std::cerr << "Cannot open the output file\n";
    return 2;
  }
  if (firstArgument == 1)
  {
    int matrix[rows*cols];
    ara::inputStatMatrix(input,matrix,rows*cols);
    for(size_t i = 0; i < rows*cols; ++i)
    {
      std::cout << matrix[i] << "\n";
    }
  }
  else
  {
    int * matrix = new int[rows*cols];
    double * smoothedMatrix = new double[rows*cols];
    ara::inputDynMatrix(input, matrix, rows*cols);
    ara::transformToSmoothMatrix(matrix, smoothedMatrix, rows, cols);
    std::cout << "defolt\n";
    for(size_t i = 0; i < rows*cols; ++i)
    {
      std::cout << matrix[i] << "\n";
    }
    std::cout << "smooth\n";
    for(size_t i = 0; i < rows*cols; ++i)
    {
      std::cout << smoothedMatrix[i] << "\n";
    }
    delete [] matrix;
  }
  input.close();
  return 0;
}
