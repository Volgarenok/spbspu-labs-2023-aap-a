#include "read_matrix.hpp"
#include <fstream>
#include <cstddef>
#include <exception>

void poleleyko::read_matrix(std::istream& input_stream, int* array, size_t size_of_array)
{
  for (size_t i = 0; i < size_of_array; ++i)
  {
    input_stream >> array[i];
    if (!input_stream)
    {
      throw std::runtime_error("Error input");
    }
  }
  return;
}
