#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include <cstddef>
#include "base-types.hpp"
#include "shape.hpp"

namespace piyavkin
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(size_t size);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& bias);
    void move(double dx, double dy);
    CompositeShape(CompositeShape&& cs);
    CompositeShape& operator=(CompositeShape&& cs);
    CompositeShape(const CompositeShape& cs);
    CompositeShape& operator=(const CompositeShape& cs);
    size_t size() const;
    bool empty() const;
    const Shape& at(size_t i) const;
    const Shape& operator[](size_t i) const;
    Shape& operator[](size_t i);
    Shape& at(size_t i);
    void scale(double k);
    void push_back(Shape* shape);
    void pop_back();
    ~CompositeShape();
  private:
    void swap(CompositeShape& cs);
    Shape** shapes_;
    size_t size_;
    size_t capacity_;
  };
}
#endif
