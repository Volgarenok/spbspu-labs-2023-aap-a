#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace spiridonov
{

  class Parallelogram : public Shape
  {
  public:
    Parallelogram() : arrayOfPoints{ {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0} }
    {}
    Parallelogram(double x1, double x2, double x3, double y1, double y2, double y3) :
      arrayOfPoints{ {x1, y1}, {x2, y2}, {x3, y3} }
    {}
    Parallelogram(rectangle_t rect);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    ~Parallelogram() = default;
  private:
    point_t arrayOfPoints[3];
  };

}

#endif
