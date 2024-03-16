#include "base_type.hpp"
#include <stdexcept>
#include "rectangle.hpp"

shabalin::Rectangle::Rectangle(point_t leftDownCorner, point_t rightUpperCorner):
  pointLeft(leftDownCorner),
  pointRight(rightUpperCorner)
{
  if (pointLeft.y >= pointRight.y || pointLeft.x >= pointRight.x)
  {
    throw std::invalid_argument("invalid arguments");
  }
}

double shabalin::Rectangle::getArea() const
{
  double height = std::abs(pointLeft.y - pointRight.y);
  double width = std::abs(pointLeft.x - pointRight.x);
  return height * width;
}

shabalin::rectangle_t shabalin::Rectangle::getFrameRect() const
{
  point_t center({(pointLeft.x + pointRight.x) / 2, (pointLeft.y + pointRight.y) / 2});
  double height = std::abs(pointLeft.y - pointRight.y);
  double width = std::abs(pointLeft.x - pointRight.x);
  return {width, height, center};
}

void shabalin::Rectangle::move(const point_t newCenter)
{
  point_t center({(pointLeft.x + pointRight.x) / 2, (pointLeft.y + pointRight.y) / 2});
  double del_x = newCenter.x - center.x;
  double del_y = newCenter.y - center.y;
  move(del_x, del_y);
}

void shabalin::Rectangle::move(double del_x, double del_y)
{
  point_t center({(pointLeft.x + pointRight.x) / 2, (pointLeft.y + pointRight.y)});
  center.x = center.x + del_x;
  center.y = center.y + del_y;
  point_t *points[2] = {&pointLeft, &pointRight};
  for (size_t i = 0; i < 2; ++i)
  {
    points[i]->x += del_x;
    points[i]->y+= del_y;
  }
}

void shabalin::Rectangle::unsafeScale(const double ratio)
{
  double width = std::abs(pointLeft.x - pointRight.x);
  double height = std::abs(pointLeft.y - pointRight.y);

  double newWidth = width * ratio;
  double newHeight = height * ratio;

  double del_x = (newWidth - width) / 2.0;
  double del_y = (newHeight - height) / 2.0;

  pointLeft.x -= del_x;
  pointRight.x -= del_y;
  pointLeft.y += del_x;
  pointRight.y += del_y;
}

