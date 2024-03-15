#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace arakelyan
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t fp, point_t sp, point_t tp);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(point_t point);
    virtual void move(double delX, double delY);
    virtual void scaleShape(double k);
    virtual ~Parallelogram() = default;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}
#endif
