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
  const int s = rows * cols;
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
    zakozhurnikova::writeToFile(output, original, rows, cols);
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

    zakozhurnikova::substractMatrix(origin, matrix, rows, cols);
    zakozhurnikova::writeToFile(output, origin, rows, cols);
    zakozhurnikova::freeMatrix(matrix, rows);
    zakozhurnikova::freeMatrix(origin, rows);
  }

  input.close();
  output.close();
  return 0;
}
