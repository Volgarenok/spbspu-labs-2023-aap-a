#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace strelyaev
{
  class Rectangle: public Shape
  {
    public:
     Rectangle(point_t lower_left_corner, point_t upper_right_corner);
     virtual double getArea() const;
     virtual rectangle_t getFrameRect() const;
     virtual void move(point_t);
     virtual void move(double, double);
     void unsafeScale(double k) override;
    private:
     point_t p1_;
     point_t p2_;
  };
}
#endif
