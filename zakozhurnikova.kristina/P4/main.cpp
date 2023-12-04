#include "file_operation.h"
#include "matrix_operation.h"
#include <iostream>

int main(int argc, const char * argv[])
{
  int option = 0;
  try
  {
    option = zakozhurnikova::checkArguments(argc, argv);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input;
  std::ofstream output;
  try
  {
    input.open(argv[2]);
    output.open(argv[3]);
  }
  catch (const std::exception& e)
  {
    std::cerr << "Can not open file\n";
    return 2;
  }
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Can not read a number\n";
    return 2;
  }
  if (rows == 0 && cols == 0)
  {
    output << "0 0";
    return 0;
  }
  const size_t s = rows * cols;
  int staticMatrix[10000] = {};
  int *matrix = nullptr;
  int *original = nullptr;

  try
  {
    original = new int[s];
  }
  catch (const std::bad_alloc &e)
  {
    std::cout << e.what() << '\n';
    return 1;
  }

  for (size_t i = 0; i < rows; i++)
  {
    for (size_t j = 0; j < cols; j++)
    {
      input >> original[i * cols + j];
      if (!input)
      {
        std::cerr << "Incorrect input!\n";
        delete[] original;
        return 1;
      }
    }
  }

  if (option == 1)
  {
    matrix = staticMatrix;
  }
  if (option == 2)
  {
    try
    {
      matrix = new int[rows * cols]{0};
    }
    catch (const std::bad_alloc &e)
    {
      delete[] original;
      std::cerr << e.what() << '\n';
      return 1;
    }
  }
  zakozhurnikova::fillMatrix(matrix, rows, cols);
  zakozhurnikova::substractMatrix(original, matrix, rows, cols);
  zakozhurnikova::writeToDest(output, original, rows, cols);
  if (option == 2)
  {
    delete[] matrix;
  }
  delete[] original;
  return 0;
}
