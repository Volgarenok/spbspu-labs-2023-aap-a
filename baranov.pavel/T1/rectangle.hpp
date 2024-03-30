#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"

namespace baranov
{
  void pointScale(point_t & point, const point_t & center, double ratio);
  class Rectangle: public Shape
  {
    public:
      Rectangle(const point_t & ldCorner, const point_t & ruCorner);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & destPos);
      virtual void move(double dx, double dy);
    private:
      point_t ldCorner_;
      point_t ruCorner_;
      virtual void doScale(double ratio);
  };
}

#endif

