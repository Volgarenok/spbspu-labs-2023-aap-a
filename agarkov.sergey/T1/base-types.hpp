#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace agarkov
{
  struct point_t
  {
    double x;
    double y;
    void move(double dx, double dy);
    void unsaveScale(point_t center, double k);
  };

  struct rectangle_t
  {
    point_t pos;
    double width;
    double height;
  };

  point_t getLineCenter(point_t point1, point_t point2);
}

#endif
