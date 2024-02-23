#ifndef COMPLEXQUAD_HPP
#define COMPLEXQUAD_HPP
#include "shape.hpp"
#include <stdexcept>
#include "geometryFunc.hpp"

namespace zakozhurnikova
{
  class Complexquad: public Shape
  {
  public:
    Complexquad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4);
    double getArea() const;
    rectangle_t getFrameRect() const;
    void move(const point_t& p);
    void move(double dx, double dy);
    void unsafeScale(double k);

  private:
    point_t vertexes_[4];
  };
  bool hasIntersection(const point_t* points);
  bool hasEqualPoints(const point_t* points, size_t size);
  bool hasContentPoint(const point_t* points, size_t size);
  bool isPointOnLine(const point_t& p1, const point_t& p2, const point_t& p);
}
#endif

