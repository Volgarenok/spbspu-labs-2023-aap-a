#include "inputfile.hpp"


bool novokhatskiy::inputfile(std::istream& input, int* matrix, int rows, int cols, int num)
{
  if (num == 1)
  {
    for (int i =  0; i < rows * cols; ++i)
    {
      if (!(input >> matrix[i]))
      {
        return false;
      }
    }
    return true;
  }
  else
  {
    for (int i = 0; i < rows * cols; ++i)
    {
      if(!(input >> matrix[i]))
      {
        return false;
      }
    }
    return true;
  }
}
