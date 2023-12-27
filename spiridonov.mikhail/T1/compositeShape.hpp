#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "shape.hpp"

namespace spiridonov
{
  struct CompositeShape
  {
    size_t shapes;
    size_t capacity;
    Shape* shapeptrs;

    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other) noexcept;
    ~CompositeShape();
}

#endif
