#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
namespace strelyaev
{
  class Triangle: public Shape
  {
    public:
     Triangle(point_t, point_t, point_t);
     virtual double getArea() const;
     virtual rectangle_t getFrameRect() const;
     virtual void move(point_t);
     virtual void move(double, double);
    private:
     virtual void doScale(double) override;
     double getDistance(point_t, point_t) const;
     point_t p1_;
     point_t p2_;
     point_t p3_;
  };
}
#endif