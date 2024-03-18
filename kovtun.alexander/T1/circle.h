#ifndef CIRCLE_H
#define CIRCLE_H

#include "shape.h"

namespace kovtun
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t & center, double radius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(double dx, double dy);
    virtual void scale(double k);

  private:
    point_t center_;
    double radius_;
  };
}

#endif
