#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include <iostream>
#include "shape.hpp"
#include "triangle.hpp"

namespace ishmuratov
{
  class Concave: public Shape
  {
    public:
      Concave(const point_t & point1, const point_t & point2, const point_t & point3, const point_t & point4);
      virtual ~Concave();
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
