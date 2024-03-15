#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"
#include "base-types.hpp"

namespace rebdev
{
  class Rectangle: public Shape
  {
    public:
      Rectangle(const point_t & lowLeftCorner, const point_t & upRightCorner);

      virtual ~Rectangle() = default;
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double x, double y);
      virtual void scale(double k);
    private:
      point_t corners_[2];
  };
}

#endif
