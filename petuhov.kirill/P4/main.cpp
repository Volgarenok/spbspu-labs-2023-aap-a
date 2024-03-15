
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "islowertriangular.hpp"
#include "fillMatrix.hpp"

int main(int argc, char **argv)
{
  if (argc != 4)
  {
    std::cerr << "Not enough arguments";
    return 1;
  }
  int arr_type = 0;
  try
  {
    size_t pos = 0;
    arr_type = std::stoi(argv[1], &pos);
    if (argv[1][pos] != '\0')
    {
      throw std::invalid_argument("Invalid argument: not a valid integer");
    }
    else if (arr_type != 1 && arr_type != 2)
    {
      throw std::out_of_range("Argument is out of range. Argument must be 1 or 2.");
    }
  }
  catch (const std::exception &e)
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

  if (rows == 0 || cols == 0)
  {
    std::ofstream outputFile(argv[3]);
    if (!outputFile)
    {
      std::cerr << "Cannot write output\n";
      return 5;
    }
    return 0;
  }

  int *matrix = nullptr;
  bool is_lower_triangular = false;

  try
  {
    if (arr_type == 1)
    {
      int fixed_matrix[10000] = {};
      matrix = fixed_matrix;
      petuhov::fillMatrix(matrix, rows, cols, inputFile);
      is_lower_triangular = petuhov::isLowerTriangular(matrix, rows, cols);
    }
    else if (arr_type == 2)
    {
      if (rows == 0 || cols == 0)
      {
        throw std::invalid_argument("Invalid matrix dimensions: rows or columns is zero");
      }

      matrix = new int[rows * cols];
      petuhov::fillMatrix(matrix, rows, cols, inputFile);
      is_lower_triangular = petuhov::isLowerTriangular(matrix, rows, cols);
      delete[] matrix;
    }
  }
  catch (const std::exception &e)
  {
    std::cerr << "An error occurred: " << e.what() << "\n";
    if (arr_type == 2 && matrix != nullptr)
    {
      delete[] matrix;
    }
    return 4;
  }

  std::ofstream outputFile(argv[3]);
  if (!outputFile)
  {
    std::cerr << "Cannot write output\n";
    return 5;
  }
  outputFile << is_lower_triangular << "\n";
  return 0;
}
