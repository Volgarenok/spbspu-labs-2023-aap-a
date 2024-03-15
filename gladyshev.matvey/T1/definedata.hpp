#ifndef DEFINEDATA_HPP
#define DEFINEDATA_HPP

#include <cstddef>
#include <string>
#include <istream>

#include "base-types.hpp"
#include "shape.hpp"

namespace gladyshev
{
  void inputPoints(std::istream& in, double * arrcords, size_t counter);
  void freeMemory(Shape ** shapes, size_t amount);
  Shape * identifyShape(const std::string& inputName, std::istream& in);
  void isoScale(Shape * shapes, point_t pos, double factor);
  void scalePoint(point_t& p, double factor, rectangle_t frame);
}

#endif
