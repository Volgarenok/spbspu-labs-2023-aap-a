#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace grechishnikov
{
  class Polygon: public Shape
  {
  public:
    Polygon(const point_t* points, size_t size);
    ~Polygon();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& pos);
    virtual void move(double dx, double dy);
    virtual void unsafeScale(double rate);
  private:
    point_t* points_;
    size_t size_;
  };
}

#endif
