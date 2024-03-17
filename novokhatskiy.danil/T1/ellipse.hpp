#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP
#include "shape.hpp"

namespace novokhatskiy
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(const point_t &center, double vert, double horizon);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(double x, double y);
    virtual void scale(double ratio);

  private:
    point_t center_;
    double vert_;
    double horizon_;
  };
}

#endif
