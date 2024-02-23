#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace piyavkin
{
  class Triangle: public Shape
  {
  public:
    Triangle(const point_t& p1, const point_t& p2, const point_t& p3);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(const point_t& bias) override;
    void move(double dx, double dy) override;
    Shape* clone() const override;
    void unsafeScale(double k) override;
  private:
    point_t a_;
    point_t b_;
    point_t c_;
  };
}
#endif
