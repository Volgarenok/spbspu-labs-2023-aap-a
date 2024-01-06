#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.hpp"

namespace namestnikov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t & center, const double radius);
    virtual double getArea();
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double coefficient);
    ~Circle() = default;
  private:
     point_t circleCenter_;
     double circleRadius_;
  };
}

#endif
