#ifndef BASE_TYPE_HPP 
#define BASE_TYPE_HPP

namespace shabalin
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
    point_t position;
  };
}

#endif
