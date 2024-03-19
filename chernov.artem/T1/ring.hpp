#ifndef RING_HPP
#define	RING_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace chernov
{
  class Ring : public Shape
  {
  public:
    Ring(point_t center, double outer_radius, double inner_radius);
    ~Ring() = default;
    double getArea() const override;
    rectangle_t getFrameRect() override;
    void move(point_t pos) override;
    void move(double moveX, double moveY) override;
    void scale(double multiplier) override;
    Shape* clone() const override;
  private:
    point_t center_;
    double outer_radius_;
    double inner_radius_;
  };
}

#endif
