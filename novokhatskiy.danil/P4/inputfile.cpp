#include "inputfile.hpp"

void novokhatskiy::sInputFile(std::istream& input, int* matrix, int e)
{
  for(int i = 0; i < e; i++)
  {
    if(!(input >> matrix[i]))
    {
      throw(std::logic_error("Imposible to create matrix\n"));
    }
  }
}

void novokhatskiy::dInputFile(std::ifstream& input, int* matrix, int e)
{
  for (int i = 0; i < e; i++)
  {
    if(!(input >> matrix[i]))
    {
      delete[] matrix;
      throw (std::logic_error("Imposible to create matrix\n"));
    }
  }
}
