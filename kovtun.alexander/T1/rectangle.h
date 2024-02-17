#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "shape.h"

namespace kovtun
{
  class Rectangle : public Shape
  {
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t point);
    void move(double dx, double dy);
    void scale(double k);
  };
}

#endif

