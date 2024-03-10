#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace petuhov
{
  struct point_t
  {
    float x;
    float y;
  };

  struct rectangle_t
  {
    point_t pos;
    float width;
    float height;
  };
}

#endif
