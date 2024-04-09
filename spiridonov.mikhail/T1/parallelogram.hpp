#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace spiridonov
{
  class Parallelogram: public Shape
  {
  public:
    Parallelogram(double x1, double x2, double x3, double y1, double y2, double y3);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double coefficient);
    Parallelogram* clone() const;
    ~Parallelogram();
  private:
    point_t arrayOfPoints_[3];
  };
}

#endif

