#ifndef REGULAR_HPP
#define REGULAR_HPP

#include "shape.hpp"

namespace isaychev
{
  class Regular: public Shape
  {
   public:
    Regular(const point_t & p1, const point_t & p2, const point_t & p3);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & newPos);
    virtual void move(double dX, double dY);

   private:
    point_t center_;
    point_t closePnt_;
    point_t distPnt_;
    virtual void doScale(double coeff);
  };
}

#endif
