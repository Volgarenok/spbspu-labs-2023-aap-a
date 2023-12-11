#include <fstream>
#include <string>
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
  long int lengthOfArr = 0;
  while (argv[1][lengthOfArr] != '\0')
  {
    lengthOfArr++;
  }
  char * endPtr = nullptr;
  long long int ctrl_parameter = std::strtoll(argv[1], &endPtr, 10);
  if (endPtr == argv[1] || (endPtr != argv[1] && (endPtr - argv[1] < lengthOfArr)))
  {
    std::cerr << "First parameter is not a number\n";
    return 1;
  }
  else if ((ctrl_parameter > 2 || ctrl_parameter < 1) && endPtr != argv[1])
  {
    std::cerr << "First parameter is out of range\n";
    return 1;
  }
  size_t rows = 0;
  size_t columns = 0;
  std::ifstream input(argv[2]);
  input >> rows >> columns;
  if (!input)
  {
    std::cerr << "Number of rows and columns in array must be described as positive integer number\n";
    return 2;
  }
  else if (columns == 0 && rows == 0)
  {
    std::ofstream output(argv[3]);
    output << rows << "\n";
    return 0;
  }
  int * dynMatrix = nullptr;
  int * arrName = nullptr;
  size_t lineSearch = 0;
  int matrixStat[10000] = {};
  arrName = matrixStat;
  if (ctrl_parameter == 2)
  {
    dynMatrix = new int[rows * columns]{};
    arrName = dynMatrix;
  }
  try
  {
    isaychev::fillMatrix(input, arrName, rows, columns);
  }
  catch (const std::invalid_argument &e)
  {
    std::cerr << e.what() << "\n";
    if (dynMatrix != nullptr)
    {
      delete [] dynMatrix;
    }
    return 2;
  }
  lineSearch = isaychev::searchLines(arrName, rows, columns);
  std::ofstream output(argv[3]);
  output << lineSearch << "\n";
  if (dynMatrix != nullptr)
  {
    delete [] dynMatrix;
  }
}

