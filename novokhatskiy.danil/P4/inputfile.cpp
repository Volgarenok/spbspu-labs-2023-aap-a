#include "inputfile.hpp"

using namespace novokhatskiy;
int inputfile(int matrix[], int rows, int cols, std::ifstream &input)
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
