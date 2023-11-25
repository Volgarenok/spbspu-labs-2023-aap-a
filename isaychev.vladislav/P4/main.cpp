#include <iostream>
#include "fillMatrix.hpp"
#include "searchLines.hpp"

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
    int matrixStat[10000] = {};
    std::ifstream input(argv[2]);
    input >> rows >> columns;
    if (!input)
    {
      std::cerr << "Number of rows and columns in array must be described as positive integer number\n";
      return 2;
    }
    if (columns == 0 && rows == 0)
    {
      std::ofstream output(argv[3]);
      output << rows << "\n";
      return 0;
    }
    try
    {
      isaychev::fillMatrix(input, matrixStat, rows, columns);
    }
    catch (const std::invalid_argument &e)
    {
      std::cerr << e.what() << "\n";
      return 2;
    }
    std::ofstream output(argv[3]);
    output << isaychev::searchLines(matrixStat, rows, columns) << "\n";
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
    if (columns == 0 && rows == 0)
    {
      std::ofstream output(argv[3]);
      output << rows << "\n";
      return 0;
    }
    else
    {
      int * dynMatrix = new int[rows * columns]();
      try
      {
        isaychev::fillMatrix(input, dynMatrix, rows, columns);
      }
      catch(const std::invalid_argument &e)
      {
        std::cerr << e.what() << "\n";
        delete[] dynMatrix;
        return 2;
      }
      std::ofstream output(argv[3]);
      output << isaychev::searchLines(dynMatrix, rows, columns) << "\n";
      delete[] dynMatrix;
    }
  }
}
