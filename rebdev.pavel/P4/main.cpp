#include <iostream>
#include <fstream>
#include <limits>
#include <stdexcept>
#include "matrix.hpp"

int main(int argc, char ** argv)
{
  if (argc != 4)
  {
    std::cerr << "Incorrect number of arguments\n";
    return 1;
  }

  std::ifstream input(argv[2]);
  if (!input.is_open())
  {
    std::cerr << "Cann't open " << argv[2] << '\n';
  }
  
  size_t rows = 0, colums = 0;
  input >> rows >> colums;
  if (!input)
  {
    std::cerr << "Error: in reading the number of rows or columns\n";
    return 2;
  }
  if (rows > (std::numeric_limits< size_t >::max()/colums))
  {
    throw std::overflow_error("Error: there are too many elements in the matrix\n");
  }
  
  using namespace rebdev;
  
  matrix myMatrix(rows, colums);
  
  int arrayMode = std::stoi(argv[1]);

  if (arrayMode == 1)
  {
    long long int arrMatrix[10000];
    myMatrix.filling(input, arrMatrix);
    
    input.close();

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Cann't open " << argv[3] << '\n';
      return 1;
    }
  
    output << myMatrix.localMax(arrMatrix);
    output.close();
  }
  else if (arrayMode == 2)
  {
    long long int * arrMatrix = new long long int[colums * rows];
    myMatrix.filling(input, arrMatrix);
    
    input.close();

    std::ofstream output(argv[3]);
    if (!output.is_open())
    {
      std::cerr << "Cann't open " << argv[3] << '\n';
      return 1;
    }
  
    output << myMatrix.localMax(arrMatrix);
    output.close();
  }
  else
  {
    std::cerr << "Incorrect first parameter\n";
    return 1;
  }
  
  return 0;
}
