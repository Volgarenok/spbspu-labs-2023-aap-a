#ifndef REGULAR_HPP
#define REGULAR_HPP

#include <cstddef>
#include "shape.hpp"
#include "triangle.hpp"

namespace vyzhanov
{
  class Regular: public Shape
  {
  public:
    Regular(const point_t& p1, const point_t& p2, const point_t& p3);
    virtual ~Regular();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& pos);
    virtual void move(double dx, double dy);
    virtual void scale(const double ratio);
  private:
    Triangle* triangles_;
    size_t size_;
  };
}

#endif
