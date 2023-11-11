#include <iostream>
#include <string>
#include <fstream>

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
  std::ifstream inputFile(argv[2]);
  input >> rows >> cols;
  if (!input)
  {
    std::cerr << "The contents of the file cannot be interpreted\n";
    return 2;
  }
  if (num == 1)
  {
    const arraySize = 10000;
    int matrix = [arraySize];
    if (arrayCheck(input, matrix, rows, cols))
    {
      /...
      return 0;
    }
    else
    {
      std::cerr << "The contents of the file cannot be interpreted\n";
      return 2;
    }
  }
}
