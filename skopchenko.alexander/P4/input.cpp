#include "input.h"
#include <fstream>

void skopchenko::input(std::istream& iFile, int* matrix, size_t rows, size_t cols)
{
  for (size_t i = 0; i < rows * cols; i++)
  {
    if (!(iFile >> matrix[i]))
    {
      throw std::logic_error("Bad input");
    }
  }
}
