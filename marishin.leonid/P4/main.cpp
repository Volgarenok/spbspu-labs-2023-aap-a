#include <fstream>
#include "arraycheck.hpp"
#include "matrixtransformation.hpp"

int main(int argc, char* argv[])
{
  using namespace marishin;
  if (argc < 4)
  {
    std::cerr << "Not enough arguments\n";
    return 1;
  }
  else if (argc > 4)
  {
    std::cerr << "Too many arguments\n";
    return 1;
  }
  int num = 0;
  try
  {
    char* end = nullptr;
    num = std::strtoll(argv[1], std::addressof(end), 10);
    if (*end != '\0')
    {
      throw std::invalid_argument("Incorrect value");
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 1;
  }
  if (num != 1 && num != 2)
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t rows = 0;
  size_t cols = 0;
  std::ifstream input(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "The contents of the file cannot be interpreted\n";
    return 2;
  }
  int* matrix = nullptr;
  constexpr int arraySize = 10000;
  int staticMatrix[arraySize]{};
  if (num == 1)
  {
    matrix = staticMatrix;
  }
  else if (num == 2)
  {
    matrix = new int[rows * cols];
  }
  if (checkArray(input, matrix, rows, cols) != rows * cols)
  {
    std::cerr << "Invalid matrix\n";
    if (num == 2)
    {
      delete[] matrix;
    }
    return 2;
  }
  transformMatrix(matrix, rows, cols);
  std::ofstream output(argv[3]);
  outputMatrix(output, matrix, rows, cols);
  if (num == 2)
  {
    delete[] matrix;
  }
}
