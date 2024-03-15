#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace baranov
{
  class Ellipse: public Shape
  {
    public:
      Ellipse(const point_t & center, double xRadius, double yRadius);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double dx, double dy);
    private:
      point_t center_;
      double yRadius_;
      double xRadius_;
      virtual void doScale(double ratio);
  };
}

#endif

