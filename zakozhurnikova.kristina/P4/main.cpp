#include "file_operation.h"
#include "matrix_operation.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>

int main(int argc, char * argv[])
{
  int option = 0;
  try
  {
    zakozhurnikova::rightArguments(argc, argv);
  }
  catch (const std::invalid_argument& e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }
  int rows = 0;
  int cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  const int s = rows * cols;
  if (!input)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  if (option == 1)
  {
    int matrix[s]{};
    int original[s]{};
    zakozhurnikova::fillMatrix(matrix, rows, cols);

    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        input >> original[i*cols + j];
      }
    }
    zakozhurnikova::substractMatrix(original, matrix, rows, cols);
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        std::cout << original[i*rows + j] << ' ';
      }
      std::cout << '\n';
    }
  }
  else
  {
    int **matrix = nullptr;
    int **origin = nullptr;
    if (!input)
    {
      std::cerr << "Incorrect input!\n";
      return 1;
    }
    try
    {
      zakozhurnikova::createMatrix(matrix, rows, cols);
      zakozhurnikova::createMatrix(origin, rows, cols);
    }
    catch (const std::exception &e)
    {
      std::cerr << e.what() << '\n';
      return 1;
    }

    zakozhurnikova::fillMatrix(matrix, rows, cols);
    for (int i = 0; i < rows; i++)
    {
      for (int j = 0; j < cols; j++)
      {
        input >> origin[i][j];
        if (!input)
        {
          std::cerr << "Incorrect input!\n";
          zakozhurnikova::freeMatrix(matrix, rows);
          zakozhurnikova::freeMatrix(origin, rows);
          return 1;
        }
      }
    }

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        std::cout << origin[i][j] << ' ';
      }
      std::cout << '\n';
    }
    std::cout << '\n';
    zakozhurnikova::substractMatrix(origin, matrix, rows, cols);

    for (int i = 0; i < rows; ++i)
    {
      for (int j = 0; j < cols; ++j)
      {
        std::cout << origin[i][j] << ' ';
      }
        std::cout << '\n';
    }
    zakozhurnikova::freeMatrix(matrix, rows);
    zakozhurnikova::freeMatrix(origin, rows);
  }
  input.close();
  return 0;
}

