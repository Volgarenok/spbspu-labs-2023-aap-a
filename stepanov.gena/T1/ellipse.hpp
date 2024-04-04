#ifndef ELLIPSE_HPP
#define ELLIPSE_HPP

#include "shape.hpp"

namespace stepanov
{
  class Ellipse: public Shape
  {
  public:
    Ellipse(const point_t& center, double radiusY, double radiusX);
    ~Ellipse() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& p);
    virtual void move(double dx, double dy);
  private:
    point_t center_;
    double radiusY_;
    double radiusX_;
    virtual void doScale(double ratio);
  };
}

#endif
