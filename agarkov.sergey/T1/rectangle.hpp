#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace agarkov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(point_t left_bottom, point_t right_top);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    bool isCorrectRectangle() const;
    point_t left_bottom_;
    point_t right_top_;
  };
}

#endif
