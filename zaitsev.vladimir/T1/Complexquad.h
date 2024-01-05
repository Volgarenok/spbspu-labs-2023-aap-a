#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include "base-types.h"
#include "Shape.h"

namespace zaitsev
{
  class Complexquad : public Shape
  {
  public:
    Complexquad(const point_t* sections);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void scale(double factor);
    point_t getCenter() const;
  private:
    point_t vertices_[4];
  };
}
#endif
