#include "output_matrix.hpp"
#include <fstream>
#include <cstddef>
#include <exception>

void poleleyko::output_matrix(std::ostream& output_stream, const int* array, const size_t size_of_array)
{
  for (size_t i = 0; i < size_of_array; ++i)
  {
    output_stream << " " << array[i];
    if (!output_stream)
    {
      throw std::runtime_error("Error input");
    }
  }
  return;
}
