#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "shape.hpp"

namespace petuhov
{
  class Circle : public Shape
  {
  public:
    Circle(const point_t &center, double radius);

    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t &newPos) override;
    void move(double dx, double dy) override;
    void scale(double factor) override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif
