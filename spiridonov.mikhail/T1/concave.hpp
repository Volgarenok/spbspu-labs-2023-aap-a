#ifndef CONCAVE_HPP
#define CONCAVE_HPP
#include "shape.hpp"
#include "base-types.hpp"

namespace spiridonov
{

  class Concave : public Shape
  {
  public:
    Concave() : arrayOfPoints{ {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0}, {0.0, 0.0} },
      frameRect_{ 0.0, 0.0, {0.0, 0.0} }
    {}
    Concave(point_t p1, point_t p2, point_t p3, point_t p4);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double coefficient) override;
    Concave* clone() const override;
    ~Concave() = default;
  private:
    point_t arrayOfPoints[4];
    rectangle_t frameRect_;
    void updateFrameRect();
  };

}

#endif
