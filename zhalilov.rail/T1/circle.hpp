#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace zhalilov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);
    virtual ~Circle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double ratio);
  private:
    point_t m_center;
    double m_radius;
  };
}

#endif
