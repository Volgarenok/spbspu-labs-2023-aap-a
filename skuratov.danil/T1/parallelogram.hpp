#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace skuratov
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3);
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& A);
    virtual void move(double dx, double dy);
    virtual void scale(double scalingFactor);
    virtual ~Parallelogram() = default;
  private:
    point_t p1_;
    point_t p2_;
    point_t p3_;
  };
}

#endif
