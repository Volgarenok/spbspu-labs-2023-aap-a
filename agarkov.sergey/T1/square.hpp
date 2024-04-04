#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace agarkov
{
  class Square: public Shape
  {
  public:
    Square(point_t left_bottom, double length);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    bool isCorrectSquare();
    point_t left_bottom_;
    double length_;
  };
}

#endif
