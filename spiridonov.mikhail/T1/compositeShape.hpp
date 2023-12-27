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

    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other) noexcept;

    void addShape(const Shape& shape);
    void removeShape(size_t index);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double coefficient);
  };
}

#endif
