#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace sakovskaia
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(point_t ll, point_t ur);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t);
      virtual void move(double dx, double dy);
      virtual void scaleShape(double k);
    private:
      point_t ll_;
      point_t ur_;
  };
}
#endif
