#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "shape.hpp"

namespace belokurskaya
{
  class Concave: public Shape
  {
    public:
      Concave(const point_t & a, const point_t & b, const point_t & c, const point_t & d);
      double getArea() const override;
      rectangle_t getFrameRect() const override;
      void move(const point_t & new_pos) override;
      void move(double dx, double dy) override;
      void scale(double factor) override;

    private:
      point_t a_;
      point_t b_;
      point_t c_;
      point_t d_;

      bool isTriangle() const;
      point_t calculateCentroid() const;
      bool isInsideTriangle() const;
      bool isConcave();
  };
}
#endif
