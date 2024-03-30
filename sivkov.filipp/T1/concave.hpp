#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace sivkov
{
  class Concave: public Shape
  {
  public:
    Concave(const point_t cvVer1, const point_t cvVer2, const point_t cvVer3, const point_t cvVer4);
    ~Concave();
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t newPos);
    void move(const double x, double y);
    void scale(const double k);
  private:
    point_t cvVer1_;
    point_t cvVer2_;
    point_t cvVer3_;
    point_t cvVer4_;
  };
}

#endif
