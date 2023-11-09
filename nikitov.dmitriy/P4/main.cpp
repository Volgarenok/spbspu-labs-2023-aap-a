#include <iostream>
#include <fstream>
#include <string>
#include "input_array.hpp"
#include "count_local_min.hpp"

int main(int argc, char* argv[])
{
  if (argc != 4)
  {
    std::cerr << "Error: Wrong command line input\n";
    return 1;
  }

  int type = 0;
  try
  {
    type = std::stoll(argv[1]);
  }
  catch (const std::out_of_range &)
  {
    std::cerr << "Error: First argument is out of range\n";
    return 1;
  }
  catch (const std::invalid_argument &)
  {
    std::cerr << "Error: First argument is not a number\n";
    return 1;
  }

  size_t rows = 0, cols = 0;
  size_t count = 0;

  using namespace nikitov;

  if (type == 1)
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Error: Wrong rows or cols input\n";
      return 1;
    }

    int matrix[10000];
    size_t status = inputArray(input, matrix, rows, cols);
    if (status != 0)
    {
      std::cerr << "Error: Wrong element at position: " << status << '\n';
      return 2;
    }

    size_t position = 0;
    if (rows != 0 && cols != 0)
    {
      for (size_t i = 1; i != rows - 1; ++i)
      {
        position = cols * i + 1;
        for (size_t j = 1; j != cols - 1; ++j)
        {
          countLocalMin(position, matrix, cols, count);
          ++position;
        }
      }
    }
  }
  else if (type == 2)
  {
    std::ifstream input(argv[2]);
    input >> rows >> cols;
    if (!input)
    {
      std::cerr << "Error: Wrong rows or cols input\n";
      return 1;
    }
    int * matrix = new int [rows*cols];
    size_t status = inputArray(input, matrix, rows, cols);
    if (status != 0)
    {
      std:: cerr << "Error: Wrong element at position: " << status << '\n';
      delete [] matrix;
      return 2;
    }
    size_t position = 0;
    for (size_t i = 1; i != rows - 1; ++i)
    {
      position = cols * i + 1;
      for (size_t j = 1; j != cols - 1; ++j)
      {
        countLocalMin(position, matrix, cols, count);
        ++position;
      }
    }
  }
  else
  {
    std::cerr << "Error: First number doesn't match\n";
    return 1;
  }

  std::ofstream output(argv[3]);
  output << count << '\n';
  return 0;
}
