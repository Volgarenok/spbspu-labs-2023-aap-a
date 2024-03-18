#ifndef GEOMETRY_FUNC_HPP
#define GEOMETRY_FUNC_HPP
#include <cstddef>
#include "base-types.hpp"

namespace zakozhurnikova
{
  point_t scaleShift(double k, const point_t& p1, const point_t& p2);
  double getDistance(const point_t& p1, const point_t& p2);

  void operator+=(point_t& dest, const point_t& src);
  point_t operator+(const point_t& p1, const point_t& p2);
  point_t operator-(const point_t& p1, const point_t& p2);
  point_t operator*(const point_t& p1, double k);
  point_t operator/(const point_t& p1, double k);
  bool operator==(const point_t& p1, const point_t& p2);
}


#endif
