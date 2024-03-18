#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace zaitsev
{
  struct point_t
  {
    double x;
    double y;
  };

  point_t operator+(point_t a, point_t b);
  point_t& operator+=(point_t& a, point_t b);
  point_t operator-(point_t a, point_t b);
  point_t& operator-=(point_t& a, point_t b);
  point_t operator*(point_t a, double b);
  point_t operator/(point_t a, double b);

  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}
#endif
