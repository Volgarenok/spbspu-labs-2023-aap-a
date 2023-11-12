#include "inputfile.hpp"

int novokhatskiy::inputFile(int matrix[], int rows, int cols, std::ifstream& input)
{
  for (int i = 0; i < rows * cols; i++)
  {
    if(!(input >> matrix[i]))
    {
      return -1;
    }
  }
  return 0;
}
