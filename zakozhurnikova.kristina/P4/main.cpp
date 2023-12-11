#include "file_operation.h"
#include "matrix_operation.h"
#include <iostream>
#include <fstream>

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
    std::cerr << "Can not open file";
    return 2;
  }
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Can not read a number";
    return 2;
  }

  const size_t s = rows * cols;
  int *matrix = nullptr;
  int *original = nullptr;
  int staticMatrix[10000];

  try
  {
    original = new int[s];
  }
  catch (const std::bad_alloc &e)
  {
    std::cerr << e.what() << '\n';
    return 1;
  }

  try
  {
    zakozhurnikova::writeToMatrix(input, original, rows, cols);
  }
  catch (const std::runtime_error &e)
  {
    std::cerr << e.what() << '\n';
    delete[] original;
    return 1;
  }

  if (option == 1)
  {
    matrix = staticMatrix;
  }
  if (option == 2)
  {
    try
    {
      matrix = new int[rows * cols]{};
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
  try
  {
    zakozhurnikova::writeToDest(output, original, rows, cols);
  }
  catch (const std::invalid_argument &e)
  {
    if (option == 2)
    {
      delete[] matrix;
    }
    delete[] original;
    return 0;
  }
  if (option == 2)
  {
    delete[] matrix;
  }
  delete[] original;
  return 0;
}
