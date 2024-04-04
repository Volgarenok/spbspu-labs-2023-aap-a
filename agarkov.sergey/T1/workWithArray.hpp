#ifndef WORKWITHARRAY_HPP
#define WORKWITHARRAY_HPP

#include <cstddef>
#include "shape.hpp"

namespace agarkov
{
  Shape** expandArray(Shape** array, size_t capacity, size_t buf);
  void deleteArray(Shape** array, size_t size);
}

#endif
