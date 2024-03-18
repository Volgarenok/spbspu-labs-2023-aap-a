#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace belokurskaya
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(const point_t & lower_left, const point_t & upper_right);

      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t & new_pos) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;

    private:
      point_t lower_left_;
      point_t upper_right_;
  };
}

#endif
