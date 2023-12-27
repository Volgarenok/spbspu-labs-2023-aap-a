#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include "baseTypes.hpp"

namespace spiridonov
{
  class Parallelogram : public Shape
  {
  public:
    Parallelogram() : arrayOfPoints{ {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0} }
    {}
    Parallelogram(rectangle_t rect);
    double getArea();
    rectangle_t getFrameRect();
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    ~Parallelogram();
  private:
    point_t arrayOfPoints[3];
  };
}

#endif
