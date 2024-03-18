#ifndef RESULTS_PRINTER_HPP
#define RESULTS_PRINTER_HPP

#include "shape.hpp"

#include <iostream>

namespace belokurskaya
{
  void printResults(std::ostream & output, const Shape * const * shapes, size_t shape_count);
}

#endif
