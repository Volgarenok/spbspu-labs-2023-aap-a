#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace petuhov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, float radius);

    float getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(float dx, float dy) override;
    void scale(const petuhov::point_t &center, float factor) override;

  private:
    point_t center_;
    float radius_;
  };
}

#endif
