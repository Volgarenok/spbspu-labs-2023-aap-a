#ifndef CONCAVE_HPP
#define CONCAVE_HPP

#include "base-types.hpp"
#include "shape.hpp"

namespace rebdev
{
  class Concave: public Shape
  {
    public:
      Concave(const point_t & a, const point_t & b, const point_t & c, const point_t & d);

      virtual ~Concave() = default;
      virtual double getArea() const;
      virtual rectangle_t getFrameRect() const;
      virtual void move(const point_t & point);
      virtual void move(double x, double y);
      virtual void scale(double k);
    private:
      point_t vertexes_[4];
  };

  bool isTriangle(const point_t & f, const point_t & s, const point_t & t);
}

#endif
