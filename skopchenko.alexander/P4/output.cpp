#include "output.h"
#include <fstream>
#include <iomanip>

void skopchenko::outputInt(std::ostream &oFile, const int *matrix, size_t rows, size_t cols)
{
  if (!(oFile << rows << ' ' << cols))
  {
    throw std::runtime_error("Error during output");
  }
  oFile << std::fixed;
  for (size_t i = 0; i < rows * cols - 1; ++i)
  {
    if (!(oFile << ' ' << matrix[i]))
    {
      throw std::runtime_error("Couldnt output");
    }
  }
}

void skopchenko::outputDouble(std::ostream &oFile, const double *matrix, size_t rows, size_t cols)
{
  if (!(oFile << rows << " " << cols))
  {
    throw std::runtime_error("Error during output");
  }
  oFile << std::fixed << std::setprecision(1);
  for (size_t i = 0; i < rows * cols - 1; ++i)
  {
    if (!(oFile << " " << matrix[i]))
    {
      throw std::runtime_error("Couldnt output");
    }
  }
}
