#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace spiridonov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle();
    Rectangle(double left, double bottom, double right, double top);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double dx, double dy) override;
    void scale(double coefficient) override;

  private:
    double left_;
    double bottom_;
    double right_;
    double top_;
  };
}

#endif
