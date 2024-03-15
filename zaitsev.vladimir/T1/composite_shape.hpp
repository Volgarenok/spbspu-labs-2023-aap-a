#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP
#include <cstddef>
#include <ostream>
#include "shape.hpp"

namespace zaitsev
{
  class CompositeShape
  {
  public:
    CompositeShape();
    CompositeShape(const CompositeShape& other);
    CompositeShape(CompositeShape&& other);
    ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& other);
    CompositeShape& operator=(CompositeShape&& other);
    void push_back(Shape* shape);
    void pop_back();
    Shape& at(size_t pos);
    const Shape& at(size_t pos) const;
    Shape& operator[](size_t pos);
    const Shape& operator[](size_t pos) const;
    bool empty() const;
    size_t size() const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t dest_pos);
    void move(double x_shift, double y_shift);
    void scale(double factor);
  private:
    size_t size_;
    size_t capacity_;
    Shape** shapes_;
    point_t getCenter() const;
  };

  std::ostream& operator<<(std::ostream& output, const CompositeShape& shape);
}
#endif
