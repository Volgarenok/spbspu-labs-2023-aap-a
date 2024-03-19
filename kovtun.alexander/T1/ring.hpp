#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"
#include "ellipse.hpp"

namespace kovtun
{
  class Ring : public Shape
  {
  public:
    Ring(const point_t & center, double outerRadius, double innerRadius);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(double dx, double dy);
    virtual void scale(double k);

  private:
    Ellipse outerEllipse_;
    Ellipse innerEllipse_;
  };
}

#endif

