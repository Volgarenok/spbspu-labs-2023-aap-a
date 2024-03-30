#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace chistyakov
{
  class Square: public Shape
  {
  public:
    Square(const point_t & leftDownCorner, double side);
    virtual ~Square();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(double mx, double my);
    virtual void scale(double ratio);
  private:
    point_t leftDownCorner_;
    double side_;
  };
}

#endif
