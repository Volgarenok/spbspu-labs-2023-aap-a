#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace stepanov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t& leftCorner, const point_t& rightCorner);
    ~Rectangle() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &p);
    virtual void move(double dx, double dy);
  private:
    point_t leftCorner_;
    point_t rightCorner_;
    virtual void doScale(double ratio);
  };
}

#endif
