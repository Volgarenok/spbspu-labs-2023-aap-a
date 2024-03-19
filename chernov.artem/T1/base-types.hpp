#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace chernov
{
  struct point_t
  {
    double x;
    double y;
  };
  struct rectangle_t
  {
    double width;
    double height;
    point_t pos;
    point_t left_down()
    {
      return { pos.x - width / 2, pos.y - height / 2 };
    }
    point_t right_high()
    {
      return { pos.x + width / 2, pos.y + height / 2 };
    }
  };
}

#endif
