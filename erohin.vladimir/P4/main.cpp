#include <iostream>
#include <string>
#include <fstream>

namespace erohin
{
  void statCircleFill(int (&matrix)[10000], const size_t & rows, const size_t & cols);
  void dynCircleFill(int * matrix, const size_t & rows, const size_t & cols);
}

int main(int argc, char * argv[])
{
  if (argc != 4)
  {
    std::cerr << "Wrong number of line arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    num = std::stoi(argv[1]);
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
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[rows * i + j];
      }
    }
    input.close();
    if (!input)
    {
      std::cerr << "Invalid value of matrix element\n";
      return 2;
    }
    erohin::statCircleFill(matrix, rows, cols);
    std::ofstream output(argv[3]);
    output << rows << " " << cols;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        output << " " << matrix[rows * i + j];
      }
    }
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
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        input >> matrix[rows * i + j];
      }
    }
    input.close();
    if (!input)
    {
      std::cerr << "Invalid value of matrix element\n";
      return 2;
    }
    erohin::dynCircleFill(matrix, rows, cols);
    std::ofstream output(argv[3]);
    output << rows << " " << cols;
    for (size_t i = 0; i < rows; ++i)
    {
      for (size_t j = 0; j < cols; ++j)
      {
        output << " " << matrix[rows * i + j];
      }
    }
    output.close();
    delete[] matrix;
    return 0;
  }
}

void erohin::statCircleFill(int (&matrix)[10000], const size_t & rows, const size_t & cols)
{
  size_t dist_edge_rows = 0;
  size_t dist_edge_cols = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    dist_edge_rows = std::min(i, rows - i - 1);
    for (size_t j = 0; j < cols; ++j)
    {
      dist_edge_cols = std::min(j, cols - j - 1);
      matrix[rows * i + j] += std::min(dist_edge_rows, dist_edge_cols);
    }
  }
  return;
}

void erohin::dynCircleFill(int * matrix, const size_t & rows, const size_t & cols)
{
  size_t dist_edge_rows = 0;
  size_t dist_edge_cols = 0;
  for (size_t i = 0; i < rows; ++i)
  {
    dist_edge_rows = std::min(i, rows - i - 1);
    for (size_t j = 0; j < cols; ++j)
    {
      dist_edge_cols = std::min(j, cols - j - 1);
      matrix[rows * i + j] += std::min(dist_edge_rows, dist_edge_cols);
    }
  }
  return;
}
