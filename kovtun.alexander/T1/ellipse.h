#ifndef ELLIPSE_H
#define ELLIPSE_H

#include "shape.h"

namespace kovtun
{
  class Ellipse : public Shape
  {
  public:
    Ellipse(const point_t & center, double verticalRadius, double horizontalRadius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(double dx, double dy);
    virtual void scale(double k);

  private:
    point_t center_;
    double verticalRadius_;
    double horizontalRadius_;
  };
}

#endif

