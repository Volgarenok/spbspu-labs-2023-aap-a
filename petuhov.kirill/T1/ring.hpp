#ifndef RING_HPP
#define RING_HPP

#include "shape.hpp"

namespace petuhov
{
  class Ring : public Shape
  {
  private:
    point_t center_;
    float outer_radius_;
    float inner_radius_;

  public:
    Ring(const point_t &center, float outer_radius, float inner_radius);
    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(float dx, float dy) override;
    void scale(const petuhov::point_t &center, float factor) override;
  };
}

#endif
