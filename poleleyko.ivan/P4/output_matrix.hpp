#ifndef OUTPUT_MATRIX_HPP
#define OUTPUT_MATRIX_HPP

#include <fstream>
#include <cstddef>

namespace poleleyko
{
  void output_matrix(std::ostream& input_stream, const int* array, const size_t size_of_array);
}

#endif
