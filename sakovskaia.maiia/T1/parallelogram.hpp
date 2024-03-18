#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP
#include "shape.hpp"
namespace sakovskaia
{
  class Parallelogram: public Shape
  {
    public:
      Parallelogram(point_t p1, point_t p2, point_t p3);
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(point_t new_center);
      virtual void move(double dx, double dy);
      virtual void unsafeScale(double k) override;
    private:
      point_t p1_;
      point_t p2_;
      point_t p3_;
  };
}
#endif
