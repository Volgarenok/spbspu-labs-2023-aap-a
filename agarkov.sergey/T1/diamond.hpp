#ifndef DIAMOND_HPP
#define DIAMOND_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace agarkov
{
  class Diamond: public Shape
  {
  public:
    Diamond(point_t point1, point_t point2, point_t center);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    bool isCorrectDiamond() const;
    point_t point1_;
    point_t point2_;
    point_t center_;
  };
}

#endif

