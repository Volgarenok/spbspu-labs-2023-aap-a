#include <iostream>
#include <cstdlib>
#include <fstream>

int main(int argc, char * argv[])
{
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
  char * endPtr = nullptr;
  long long int ctrl_parameter = std::strtoll(argv[1], &endPtr, 10);
  if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr != argv[1])
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  else if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr == argv[1])
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  size_t rows = 0;
  size_t columns = 0;
  if (ctrl_parameter == 1)
  {
    // starting input
    int Matrix[10000] = {};
    std::ifstream input(argv[2]);
    input >> rows >> columns;
    if (!input)
    {
      std::cerr << "Number of rows and columns in array must be described as positive integer number\n";
      return 2;
    }
    for (size_t i = 0; i < rows * columns; ++i)
    {
      input >> Matrix[i];
      if (!input)
      {
        std::cerr << "Elements of array must be described as integer\n";
        return 2;
      }
    }
  }

  else if (ctrl_parameter == 2)
  {
    std::ifstream input(argv[2]);
    input >> rows >> columns;
    if (!input)
    {
      std::cerr << "Number of rows and columns in array must be described as positive integer number\n";
      return 2;
    }
    int * DynMatrix = new int[rows * columns]();
    for (size_t i = 0; i < rows * columns; ++i)
    {
      input >> DynMatrix[i];
      if (!input)
      {
        std::cerr << "Elements of array must be described as integer\n";
        return 2;
      }
    }
    delete[] DynMatrix;
  }
}
