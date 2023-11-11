#include "inputfile.hpp"

int novokhatskiy::inputfile(int matrix[], int rows, int cols, std::ifstream &input)
{
  for (int i = 0; i < rows * cols; i++)
  {
    if (!(input >> matrix[i]))
    {
      return 5;
    }
  }
  return 0;
}
