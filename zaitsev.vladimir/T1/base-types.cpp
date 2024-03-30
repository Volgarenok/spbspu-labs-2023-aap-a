#include "base-types.hpp"

zaitsev::point_t zaitsev::operator+(point_t a, point_t b)
{
  return { a.x + b.x, a.y + b.y };
}

zaitsev::point_t& zaitsev::operator+=(point_t& a, point_t b)
{
  a.x += b.x;
  a.y += b.y;
  return a;
}

zaitsev::point_t zaitsev::operator-(point_t a, point_t b)
{
  return { a.x - b.x, a.y - b.y };
}

zaitsev::point_t& zaitsev::operator-=(point_t& a, point_t b)
{
  a.x -= b.x;
  a.y -= b.y;
  return a;
}

zaitsev::point_t zaitsev::operator*(point_t a, double b)
{
  return { a.x * b, a.y * b };
}

zaitsev::point_t zaitsev::operator/(point_t a, double b)
{
  return { a.x / b, a.y / b };
}
