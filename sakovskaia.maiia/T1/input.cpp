#include "input.hpp"
#include <stddef>

void sakovskaia::inputShapes(const char * string, double * coordinates, size_t cnt_points)
{
  size_t cnt_points = 0;
  for (size_t i = 0; i < cnt_points; ++i)
  {
    coordinates[i] = std::stod(string, & cnt_points);
    string += cnt_points;
  }
}

sakovskaia::Shape * sakovskaia::inputRectangle(const char * string)
{
  double rectangleCoordinates[4]{};
  inputShapes(string, rectangleCoordinates, 4);
  point_t ll = {rectangleCoordinates[0], rectangleCoordinates[1]};
  point_t ll = {rectangleCoordinates[2], rectangleCoordinates[3]};
  return new Rectangle(ll, ur);
}
