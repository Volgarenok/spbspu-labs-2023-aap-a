#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(point_t vertex1, point_t vertex2, point_t vertex3, point_t vertex4);
    Complexquad(const Complexquad& other) = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void unsafeScale(double factor);
    virtual Shape* clone() const;
  private:
    point_t vertices_[4];
    point_t getCenter() const;
  };
}
#endif
