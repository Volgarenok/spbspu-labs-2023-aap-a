#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace zhalilov
{
  class Rectangle : public Shape
  {
  public:
    Rectangle(const point_t &leftCorner, const point_t &rightCorner);
    virtual ~Rectangle();
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t &point);
    virtual void move(const double dx, const double dy);
    virtual void scale(const double ratio);
  private:
    point_t m_leftCorner;
    point_t m_rightCorner;;
  };
}

#endif
