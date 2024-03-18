#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP

#include <cstddef>
#include "shape.hpp"

namespace isaychev
{
  class CompositeShape
  {
   public:
    CompositeShape();
    ~CompositeShape();
    CompositeShape(CompositeShape && diffCShape);
    CompositeShape & operator=(CompositeShape && diffCShape);
    void pushBack(Shape * figure);
    void popBack();
    Shape & at(size_t n);
    const Shape & at(size_t n) const;
    Shape & operator[](size_t n);
    const Shape & operator[](size_t n) const;
    bool empty() const;
    size_t size() const;
    size_t maxSize() const;
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t & newPos);
    void move(double dX, double dY);
    void scale(double coeff);

   private:
    size_t capacity_;
    size_t currNumOfFigures_;
    Shape * figures_[1000];
  };
}

#endif
