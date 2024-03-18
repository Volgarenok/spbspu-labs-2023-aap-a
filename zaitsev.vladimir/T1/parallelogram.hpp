#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace zaitsev
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t vertex1, point_t vertex2, point_t vertex3);
    Parallelogram(const Parallelogram& other) = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t dest_pos);
    virtual void move(double x_shift, double y_shift);
    virtual void unsafeScale(double factor);
    virtual Shape* clone() const;
  private:
    point_t def_vertices_[3];
    point_t getCenter() const;
  };
}
#endif
