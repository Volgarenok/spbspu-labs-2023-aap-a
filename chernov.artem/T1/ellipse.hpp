#ifndef ELLIPSE_HPP
#define	ELLIPSE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace chernov
{
  class Ellipse : public Shape
  {
  public:
    Ellipse(point_t center, double vertical_radius, double horizontal_radius);
    ~Ellipse() = default;
    double getArea() const override;
    rectangle_t getFrameRect() override;
    void move(point_t pos) override;
    void move(double moveX, double moveY) override;
    void scale(double multiplier) override;
    Shape* clone() const override;
  private:
    point_t center_;
    double vertical_radius_;
    double horizontal_radius_;
  };
}

#endif
