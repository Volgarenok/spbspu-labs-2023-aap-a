#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <stdexcept>
#include "shape.hpp"
#include "triangle.hpp"

namespace ishmuratov
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(const point_t & point1, const point_t & point2);
      virtual ~Rectangle();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t position);
      virtual void move(double dx, double dy);
      virtual void scale(double factor);
    private:
      Triangle tri1_;
      Triangle tri2_;
  };
}

#endif
