#ifndef READ_MATRIX_HPP
#define READ_MATRIX_HPP

#include <fstream>
#include <cstddef>

namespace poleleyko
{
  void read_matrix(std::istream& input_stream, int* array, size_t size_of_array);
}

#endif
