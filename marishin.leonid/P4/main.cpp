#include <string>
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
  char* end = nullptr;
  int num = std::strtoll(argv[1], std::addressof(end), 10);
  if (*end != '\0')
  {
    std::cerr << "Incorrect value\n";
    return 1;
  }
  try
  {
    num = std::stoll(argv[1]);
  }
  catch (const std::out_of_range&)
  {
    std::cerr << "Value out of range\n";
    return 1;
  }
  catch (const std::invalid_argument&)
  {
    std::cerr << "First parameter is not a number\n";
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
  try
  {
    if (num == 1)
    {
      const int arraySize = 10000;
      int matrix[arraySize]{};
      processingMatrix(input, matrix, rows, cols, num, argv[3]);
    }
    else if (num == 2)
    {
      int* matrix = new int[rows * cols];
      processingMatrix(input, matrix, rows, cols, num, argv[3]);
    }
  }
  catch (const std::exception& e)
  {
    std::cerr << "ERROR: " << e.what() << "\n";
    return 2;
  }
}
