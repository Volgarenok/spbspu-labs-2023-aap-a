#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace chernov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle():
      left_down_{0.0, 0.0},
      right_high_{0.0, 0.0}
    {};
    Rectangle(double x_left_down, double y_left_down, double x_right_high, double y_right_high):
      left_down_{ x_left_down, y_left_down },
      right_high_{ x_right_high, y_right_high }
    {};
    Rectangle(point_t left_down, point_t right_high) :
      left_down_(left_down),
      right_high_(right_high)
    {};
    double getArea() const override;
    rectangle_t getFrameRect() override;
    void move(point_t pos) override;
    void move(double moveX, double moveY) override;
    void scale(double multiplier) override;
    ~Rectangle() = default;
    Shape* clone() const override;
  private:
    point_t left_down_;
    point_t right_high_;
  };
}

#endif
