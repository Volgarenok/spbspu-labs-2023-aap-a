#ifndef STRING_PROCESSING_HPP
#define STRING_PROCESSING_HPP
#include <ostream>
#include "shape.hpp"
#include "base-types.hpp"
namespace strelyaev
{
  void scaleCommand(const char*, Shape* const*, size_t, std::ostream&);
  void toScaleIso(Shape*, point_t, double);
  void scaleShapes(Shape* const*, size_t, const double*, std::ostream&);
  void outputShapes(std::ostream&, const Shape* const*, size_t);
}
#endif
