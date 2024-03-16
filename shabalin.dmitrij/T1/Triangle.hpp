#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace shabalin
{
  class Triangle: public Shape
  {
    public: 
      Triangle(point_t &, point_t &, point_t &);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t);
      virtual void move(double, double);
      virtual void unsafeScale(const double ratio);
    private:
      point_t p1_;
      point_t p2_;
      point_t p3_;
      double getLength(point_t p1, point_t p2) const;
  };
}
#endif
