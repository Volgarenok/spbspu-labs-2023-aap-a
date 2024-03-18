#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP

#include <stdexcept>
#include <cmath>
#include <cstddef>
#include "shape.hpp"
#include "base-types.hpp"

namespace sivkov
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t newPos);
    void move(const double x, const double y);
    void scale(const double k);
  private:
    point_t cqVer1_;
    point_t cqVer2_;
    point_t cqVer3_;
    point_t cqVer4_;
  };
}

#endif

