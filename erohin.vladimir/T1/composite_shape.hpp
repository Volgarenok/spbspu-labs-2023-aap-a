#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace erohin
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& rhs);
    CompositeShape(CompositeShape&& rhs) noexcept;
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& rhs);
    CompositeShape& operator=(CompositeShape&& rhs) noexcept;
    Shape* operator[](size_t index);
    const Shape* operator[](size_t index) const;
    Shape* at(size_t index);
    const Shape* at(size_t index) const;
    void push(const Shape* shape);
    void pop();
    bool empty() const;
    size_t size() const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(double dx, double dy);
    void move(point_t point);
    void scale(double ratio);
  private:
    size_t capacity_;
    size_t size_;
    Shape** shape_;
    void swap(CompositeShape& rhs);
    void resize(size_t length);
  };
  void freeShape(Shape** shape, size_t size);
}

#endif
