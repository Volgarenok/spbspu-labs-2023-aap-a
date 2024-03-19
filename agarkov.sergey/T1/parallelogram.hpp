#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace agarkov
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(point_t point1, point_t point2, point_t point3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(double dx, double dy) override;
    void move(point_t position) override;
    void scale(double k) override;
  private:
    bool isCorrectParallelogram() const;
    point_t point1_;
    point_t point2_;
    point_t point3_;
  };
}

#endif


