#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace gladyshev
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(const point_t& p1, const point_t& p2);
      virtual ~Rectangle();
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(double dx, double dy);
      virtual void move(const point_t& pos);
      virtual void unsafeScale(double factor);
    private:
      point_t p1FrameRec_;
      point_t p2FrameRec_;
  };
}

#endif
