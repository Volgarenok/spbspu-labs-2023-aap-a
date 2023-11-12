#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdexcept>
#include "circle_fill.hpp"
#include "read_print_matrix.hpp"
#include "max_main_diagonal.hpp"

int main(int argc, char * argv[])
{
  using namespace erohin;
  if (argc != 4)
  {
    std::cerr << "Wrong number of line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Value of first CLA is too large\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "First argument is not a number\n";
    return 1;
  }
  if (num > 2)
  {
    std::cerr << "Wrong task number\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "Cannot read a number of rows and columns\n";
    return 2;
  }
  if (num == 1) //handling using static array
  {
    int matrix[10000] = {0};
    try
    {
      readMatrix(input, matrix, rows, cols);
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    input.close();
    try
    {
      circleFill(matrix, rows, cols);
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what() << "\n";
      return 4;
    }
    std::ofstream output(argv[3]);
    output << rows << " " << cols;
    printMatrix(output, matrix, rows, cols);
    output.close();
  }
  else if (num == 2) //handling using dynamic array
  {
    int * matrix = nullptr;
    try
    {
      matrix = new int[rows * cols];
    }
    catch (const std::bad_alloc &)
    {
      delete[] matrix;
      std::cerr << "Error of allocation memory in free store\n";
      return 3;
    }
    try
    {
      readMatrix(input, matrix, rows, cols);
    }
    catch (const std::exception & e)
    {
      delete[] matrix;
      std::cerr << e.what() << "\n";
      return 2;
    }
    input.close();
    try
    {
      circleFill(matrix, rows, cols);
    }
    catch (const std::exception & e)
    {
      std::cerr << e.what() << "\n";
      return 4;
    }
    std::ofstream output(argv[3]);
    output << rows << " " << cols;
    printMatrix(output, matrix, rows, cols);
    output.close();
    delete[] matrix;
    return 0;
  }
}
