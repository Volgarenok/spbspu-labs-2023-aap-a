#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"
namespace sakovskaia
{
  class Ellipse: public Shape
  {
    public:
      Ellipse(const point_t & center, double radiusX, double radiusY);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t new_center);
      virtual void move(double dx, double dy);
      virtual void scaleShape(double k) override;
    private:
      point_t center_;
      double radiusX_;
      double radiusY_;
  };
}
#endif
