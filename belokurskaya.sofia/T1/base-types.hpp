#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace belokurskaya
{
  struct point_t
  {
    double x;
    double y;

    bool operator==(const point_t & other) const
    {
      return x == other.x && y == other.y;
    }
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };
}

#endif
