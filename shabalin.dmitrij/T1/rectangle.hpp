#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
namespace shabalin
{
  class Rectangle:
    public Shape 
  {
    public:
      Rectangle(point_t leftCorner, point_t rightCorner);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t);
      virtual void move(double, double);
      virtual void unsafeScale(const double ratio);
    private: 
      point_t pointLeft;
      point_t pointRight;
  };
}
#endif
