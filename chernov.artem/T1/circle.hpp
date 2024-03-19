#ifndef CIRCLE_HPP
#define CIRCLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace chernov
{
  class Circle: public Shape
  {
  public:
    Circle(point_t center, double radius);
    ~Circle() = default;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double moveX, double moveY) override;
    void scale(double multiplier) override;
    Shape* clone() const override;

  private:
    point_t center_;
    double radius_;
  };
}

#endif
