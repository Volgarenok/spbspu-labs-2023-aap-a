#ifndef SQUARE_HPP
#define SQUARE_HPP
#include "triangle.hpp"
#include "shape.hpp"
namespace vyzhanov
{
  class Square: public Shape
  {
  public:
    Square(const point_t& leftCorner, double length);
    virtual ~Square() = default;
    virtual double getArea() const;
    virtual rectangle_t getFrameRect() const;
    virtual void move(const point_t& point);
    virtual void move(double dx, double dy);
    virtual void scale(double ratio);
  private:
    Triangle firstTri_;
    double length_;
  };
}
#endif
