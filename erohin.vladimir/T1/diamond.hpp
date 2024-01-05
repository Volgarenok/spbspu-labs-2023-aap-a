#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "base-types.hpp"
#include "rectangle.hpp"

namespace erohin
{
  class Diamond : public Shape
  {
  public:
    Diamond();
    Diamond(point_t* corner);
    virtual ~Diamond();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(double dx, double dy);
    virtual void move(point_t point);
    virtual void scale(double ratio);
  private:
    rectangle_t frameRect_;
  };
}

#endif
