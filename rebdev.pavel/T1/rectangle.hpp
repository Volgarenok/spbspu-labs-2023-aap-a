#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP
#include "shape.hpp"
#include "base-types.hpp"
namespace rebdev
{
  class Rectangle: public Shape
  {
    public:
      Rectangle();
      Rectangle(const point_t & lowLeftAngle, const point_t & upRightAngle);
      Rectangle(const double xLLA, const double yLLA, const double xURA, const double yURA);


      double getArea() const;
      rectangle_t getFrameRect();
      void move(const point_t point);
      void move(const double x, const double y);
      void scale(const double k);
    private:
      point_t lowLeftAngle_;
      point_t upRightAngle_;
  };
}
#endif
