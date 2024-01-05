#ifndef RING_HPP
#define RING_HPP
#include "shape.hpp"

namespace baranov
{
  class Ring : public Shape
  {
    public:
      Ring(const point_t & center, double outRadius, double inRadius);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double dx, double dy);
      virtual void scale(double ratio);
    private:
      point_t center_;
      double outRadius_;
      double inRadius_;
  };
}

#endif

