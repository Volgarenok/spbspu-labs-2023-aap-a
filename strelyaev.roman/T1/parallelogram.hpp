#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
namespace strelyaev
{
  class Parallelogram: public Shape
  {
    public:
     Parallelogram(point_t, point_t, point_t);
     virtual double getArea() const;
     virtual rectangle_t getFrameRect() const;
     virtual void move(point_t);
     virtual void move(double, double);
     virtual void unsafeScale(double) override;
    private:
     point_t p1_;
     point_t p2_;
     point_t p3_;
  };
}
#endif

