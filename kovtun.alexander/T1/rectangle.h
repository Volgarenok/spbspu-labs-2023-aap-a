#ifndef RECTANGLE_H
#define RECTANGLE_H

#include "base-types.h"
#include "shape.h"

namespace kovtun
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t & leftBottomCorner, const point_t & rightTopCorner);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(double dx, double dy);
    virtual void scale(double k);

  private:
    point_t leftBottomCorner_;
    point_t rightTopCorner_;
  };
}

#endif

