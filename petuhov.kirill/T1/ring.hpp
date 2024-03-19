#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace petuhov
{
  class Ring : public Shape
  {
  private:
    point_t center_;
    double outer_radius_;
    double inner_radius_;

  public:
    Ring(const point_t &center, double outer_radius, double inner_radius);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;
  };
}

#endif
