#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"

namespace shabalin
{
  class triangle: public Shape
  {
    public: 
      triangle(point_t, point_t, point_t);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t);
      virtual void move(double, double);
      virtual void unsafeScale(const double ratio);
    private:
      point_t point_[3]{};
      point_t getCenter() const;
  };
}
#endif
