#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "createMatrix.hpp"
#include "destroyMatrix.hpp"
#include "fillMatrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  int arr_type = 0;
  try
  {
    if (argc != 2)
    {
      throw std::invalid_argument("Invalid argument count. Please provide one integer argument.");
    }
    arr_type = std::stoi(argv[1]);

    if (arr_type != 1 && arr_type != 2)
    {
      throw std::out_of_range("Argument is out of range. Argument must be 1 or 2.");
    }
  }
  catch (const std::exception & e)
  {
    std::cerr << e.what() << "\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  std::ifstream inputFile(argv[2]);
  inputFile >> rows >> cols;
  if (!inputFile)
  {
    std::cerr << "Cannot read a number\n";
    return 2;
  }
  bool isLowerTriangularMatrix = true;

  if (arr_type == 1)
  {
    int matrix[10000] = {};

    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        if (!(inputFile >> matrix[i * cols + j]))
        {
          std::cerr << "Error reading matrix element at row " << i << " and column " << j << "\n";
          inputFile.close();
          return 4;
        }
      }
    }
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = i + 1; j < cols; ++j)
      {
        if (!isLowerTriangularMatrix)
        {
          break;
        }
        if(matrix[i * cols + j] != 0)
        {
          isLowerTriangularMatrix = false;
          break;
        }
      }
    }
  }
  else if (arr_type == 2)
  {
    int * matrix = nullptr;

    try
    {
      matrix = petuhov::createMatrix(rows, cols);
      try
      {
        petuhov::fillMatrix(matrix, cols, rows, inputFile);
      }
      catch(const std::runtime_error & e)
      {
        std::cerr << e.what() << '\n';
        petuhov::destroyMatrix(matrix);
        return 4;
      }
    }
    catch (const std::bad_alloc &)
    {
      std::cerr << "Not enough memory\n";
      return 4;
    }
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = i + 1; j < cols; ++j)
      {
        if (matrix[i*cols+j] != 0)
        {
          isLowerTriangularMatrix = false;
          break;
        }
      }
      if (!isLowerTriangularMatrix)
      {
        break;
      }
    }
    petuhov::destroyMatrix(matrix);
  }

  std::ofstream outputFile(argv[3]);
  if (!outputFile) {
    std::cerr << "Cannot write output\n";
    outputFile.close();
    return 5;
  }
  outputFile << isLowerTriangularMatrix << "\n";
  outputFile.close();
  return 0;
}
