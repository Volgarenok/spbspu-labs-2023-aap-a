#ifndef INPUTSHAPE_HPP
#define INPUTSHAPE_HPP
#include <istream>
#include "shape.hpp"
namespace piyavkin
{
  Shape** inputShape(std::istream& in, size_t& shapeCount);
}
#endif
