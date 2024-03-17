#ifndef COMPOSITE_SHAPE_HPP
#define COMPOSITE_SHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace nikitov
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
    Shape& operator[](size_t index);
    const Shape& operator[](size_t index) const;

    void push_back(Shape* figure);
    void pop_back();
    Shape& at(size_t index);
    const Shape& at(size_t index) const;
    size_t size() const;
    bool empty() const;

    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& point);
    void move(double dx, double dy) ;
    void scale(double ratio);
  private:
    size_t sizeOfArray_;
    Shape** figures_;
    void increaseArray();
    void decreaseArray();
    void swap(CompositeShape& other);
  };

  void deleteArray(Shape** figures, size_t numberOfFigures);
}
#endif
