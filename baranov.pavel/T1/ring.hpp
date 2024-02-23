#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace baranov
{
  class Ring: public Shape
  {
    public:
      Ring(const point_t & center, double outRadius, double inRadius);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double dx, double dy);
    private:
      point_t center_;
      double outRadius_;
      double inRadius_;
      virtual void doScale(double ratio);
  };
}

#endif

