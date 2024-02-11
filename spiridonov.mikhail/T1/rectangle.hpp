#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "base-types.hpp"
#include "shape.hpp"

namespace spiridonov
{

  class Rectangle : public Shape
  {
  public:
    Rectangle() : frameRect_{ 0.0, 0.0, {0.0, 0.0} }
    {}
    Rectangle(double width, double height, double x, double y) :
      frameRect_{ width, height, {x, y} }
    {}
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    ~Rectangle() = default;
  private:
    rectangle_t frameRect_;
  };

}

#endif
