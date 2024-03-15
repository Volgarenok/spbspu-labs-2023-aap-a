#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace chistyakov
{
  class Rectangle: public Shape
  {
  public:
    Rectangle(const point_t & leftDownCorner, const point_t & rightUpCorner);
    virtual ~Rectangle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t & point);
    virtual void move(double mx, double my);
    virtual void scale(double ratio);
  private:
    point_t leftDownCorner_;
    point_t rightUpCorner_;
  };
}

#endif
