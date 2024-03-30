#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace namestnikov
{
  class Circle: public Shape
  {
  public:
    Circle(const point_t & center, const double radius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(double dx, double dy);
    virtual void unsafeScale(double coefficient);
    ~Circle() = default;
  private:
     point_t circleCenter_;
     double circleRadius_;
     point_t getCenter() const;
  };
}

#endif
