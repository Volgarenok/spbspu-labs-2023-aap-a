#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-functions.hpp"

namespace lebedev
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & leftDownCorner, const point_t & rightUpCorner);
    virtual ~Rectangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & p);
    virtual void move(double dx, double dy);
  private:
    point_t leftDownCorner_;
    point_t rightUpCorner_;
    virtual void doScale(double ratio);
  };
}

#endif
