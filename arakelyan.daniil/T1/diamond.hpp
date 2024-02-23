#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace arakelyan
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t fp, point_t sp, point_t tp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t point);
    virtual void move(double delX, double delY);
    virtual void scaleShape(double k);
    virtual ~Diamond() = default;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}

#endif
