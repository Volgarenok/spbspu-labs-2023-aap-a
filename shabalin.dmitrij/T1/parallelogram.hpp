#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace shabalin
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(const point_t &, const point_t &, const point_t &);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &);
    virtual void move(double, double);
    virtual void scale(double);
    virtual ~Parallelogram() = default;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}

#endif