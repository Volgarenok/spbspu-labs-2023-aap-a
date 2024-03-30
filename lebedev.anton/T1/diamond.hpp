#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "base-functions.hpp"

namespace lebedev
{
  class Diamond: public Shape
  {
  public:
    Diamond(const point_t & p1, const point_t & p2, const point_t & p3);
    virtual ~Diamond() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(double dx, double dy);
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
    virtual void doScale(double ratio);
  };
}

#endif
