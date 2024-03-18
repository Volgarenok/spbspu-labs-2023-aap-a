#include "matrix_input_res.hpp"

void sakovskaia::inputMatrix(std::ifstream & input, int * a, size_t b)
{
  for (size_t i = 0; i < b; i++)
  {
    if (!(input >> a[i]))
    {
      throw std::logic_error("Cannot create matrix");
    }
  }
}

std::ostream & sakovskaia::printAnswer(std::ostream & output, const int * a, size_t b)
{
  if (!b)
  {
    throw std::logic_error("Output error");
  }
  output << a[0];
  for (size_t i = 1; i < b; i++)
  {
    output << " " << a[i];
  }
  return output;
}
