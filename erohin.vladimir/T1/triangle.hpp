#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace erohin
{
  class Triangle : public Shape
  {
  public:
    Triangle();
    Triangle(point_t * corner);
    virtual ~Triangle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void scale(double ratio);
    virtual double* getSide() const;
  private:
    point_t* vertex_;
    point_t center_;
  };
}

#endif
