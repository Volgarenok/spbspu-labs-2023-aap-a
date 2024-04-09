#include "rectangle.h"

Shape* inputRectangle(std::istream& input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  input >> x1 >> y1 >> x2 >> y2;
  if (!input)
  {
    throw std::logic_error("error");
  }
  return new Rectangle(point_t{x1, y1}, point_t{x2, y2});
}

Rectangle::Rectangle(rectangle_t rectangle):
  rectangle_(rectangle)
{}
Rectangle::Rectangle(point_t point1, point_t point2):
  rectangle_(makeFrame(point1, point2))
{
  if (point1.x >= point2.x || point1.y >= point2.y)
  {
    throw std::invalid_argument("wrong rectangle");
  }
}
double Rectangle::getArea() const
{
  return rectangle_.width * rectangle_.height;
}
rectangle_t Rectangle::getFrameRect() const
{
  return rectangle_;
}
void Rectangle::move(point_t point)
{
  rectangle_.pos = point;
}
void Rectangle::move(double dx, double dy)
{
  rectangle_.pos.x += dx;
  rectangle_.pos.y += dy;
}
void Rectangle::scale(double k) noexcept
{
  rectangle_.width *= k;
  rectangle_.height *= k;
}
Shape* Rectangle::clone() const
{
  return new Rectangle(rectangle_);
}
