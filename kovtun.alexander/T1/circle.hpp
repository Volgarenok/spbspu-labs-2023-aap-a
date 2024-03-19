#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"
#include "ellipse.hpp"

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
    // ?
    Ellipse ellipse_;
  };
}

#endif

