#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace zhalilov
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t &center, double radius);
    virtual ~Circle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(double dx, double dy);
    virtual void unsafeScale(double ratio);
  private:
    point_t m_center;
    double m_radius;
  };
}

#endif
