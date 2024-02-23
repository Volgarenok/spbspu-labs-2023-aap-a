#ifndef POLYGON_HPP
#define POLYGON_HPP

#include <cstddef>

#include "shape.hpp"

namespace zhalilov
{
  class Polygon: public Shape
  {
  public:
    Polygon(const point_t *points, size_t size);
    virtual ~Polygon();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(double dx, double dy);
    virtual void unsafeScale(double ratio);
  private:
    point_t *m_points;
    size_t m_size;

    point_t getCenter();
  };
}

#endif
