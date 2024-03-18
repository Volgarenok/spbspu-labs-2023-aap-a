#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace shabalin
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(point_t bottom_left, point_t upper_right);
    virtual ~Rectangle() = default;
    virtual void move(point_t p) override;
    virtual void move(double shift_x, double shift_y) override;
    virtual void scale(double scale) override;
    virtual double getArea() const override;
    virtual rectange_t getFrameRect() const override;
    virtual Shape *clone() const override;
  private:
    Rectangle(point_t center, size_t width, size_t height);
    point_t center_;
    double width_, height_;
  };
}
#endif
