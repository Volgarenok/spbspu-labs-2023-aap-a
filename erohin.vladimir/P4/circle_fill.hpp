#ifndef CIRCLE_FILL_HPP
#define CIRCLE_FILL_HPP

#include <cstddef>
namespace erohin
{
  void statCircleFill(int (&matrix)[10000], const size_t & rows, const size_t & cols);
  void dynCircleFill(int * matrix, const size_t & rows, const size_t & cols);
}
#endif
