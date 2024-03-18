#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include <cstddef>
#include "shape.hpp"

namespace vyzhanov
{
  class Triangle: public Shape
  {
  public:
    Triangle(const point_t& a, const point_t& b, const point_t& c);
    Triangle() = default;
    virtual ~Triangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& pos);
    virtual void move(double dx, double dy);
    virtual void scale(const double ratio);
  private:
    point_t a_, b_, c_;
  };
}

#endif
