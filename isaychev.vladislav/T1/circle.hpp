#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace isaychev
{
  class Circle: public Shape
  {
   public:
    Circle(const point_t & p, double rad);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newPos);
    virtual void move(double dX, double dY);

   private:
    point_t center_;
    double radius_;
    virtual void doScale(double coeff);
  };
}

#endif
