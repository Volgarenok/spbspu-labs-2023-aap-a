#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace stepanov
{
  class Square: public Shape
  {
  public:
    Square(const point_t& leftCorner, double length);
    ~Square() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& p);
    virtual void move(double dx, double dy);
  private:
    point_t leftCorner_;
    double length_;
    virtual void doScale(double ratio);
  };
}

#endif
