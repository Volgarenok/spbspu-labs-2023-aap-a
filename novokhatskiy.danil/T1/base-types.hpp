#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace novokhatskiy
{
  struct point_t
  {
    double x, y;
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
  };
}
#endif
