#include <iostream>
#include <fstream>
#include <cstdlib>
#include "inputMatrix.hpp"
#include "maxSumDiagonal.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Error in command line arguments\n";
    return 1;
  }
  unsigned char task = 0;
  try
  {
    size_t ind = 0;
    task = std::stoll(argv[1], std::addressof(ind));
    if (argv[1][ind] != '\0')
    {
      throw std::invalid_argument("Invalid first CLA argument\n");
    }
  }
  catch (const std::exception &)
  {
    std::cerr << "Invalid first CLA argument\n";
    return 1;
  }
  if (task != 1 && task != 2)
  {
    std::cerr << "Incorrect task number\n";
    return 1;
  }

  size_t rows = 0;
  size_t columns = 0;
  std::fstream input(argv[2]);
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Incorrect parametrs for matrix\n";
    return 2;
  }
  else if (rows == 0 || columns == 0 || rows == 1 || columns == 1)
  {
    std::ofstream output(argv[3]);
    output << 0 << '\n';
    return 0;
  }

  long long int result = 0;
  if (task == 1)
  {
    int matrix[10000] = {0};
    try
    {
      baranov::inputMatrix(input, matrix, rows, columns);
    }
    catch (...)
    {
      std::cerr << "Can not read matrix\n";
      return 2;
    }
    result = baranov::maxSumDiagonal(matrix, rows, columns);
  }
  else if (task == 2)
  {
    int * matrix = new int[rows * columns]{0};
    try
    {
      baranov::inputMatrix(input, matrix, rows, columns);
    }
    catch (...)
    {
      std::cerr << "Can not read matrix\n";
      delete[] matrix;
      return 2;
    }
    result = baranov::maxSumDiagonal(matrix, rows, columns);
    delete[] matrix;
  }
  {
    std::ofstream output(argv[3]);
    output << result << '\n';
  }
}

