#include "rectangle.hpp"
#include <stdexcept>

lebedev::Rectangle::Rectangle(const point_t & leftDownCorner, const point_t & rightUpCorner):
  leftDownCorner_(leftDownCorner),
  rightUpCorner_(rightUpCorner)
{
  if (!((leftDownCorner_.x < rightUpCorner_.x) && (leftDownCorner_.y < rightUpCorner_.y)))
  {
    throw std::invalid_argument("Error: invalid arguments for the Rectangle");
  }
}
double lebedev::Rectangle::getArea() const
{
  double width = rightUpCorner_.x - leftDownCorner_.x;
  double height = rightUpCorner_.y - leftDownCorner_.y;
  return width * height;
}
lebedev::rectangle_t lebedev::Rectangle::getFrameRect() const
{
  double width = rightUpCorner_.x - leftDownCorner_.x;
  double height = rightUpCorner_.y - leftDownCorner_.y;
  double center_x = (leftDownCorner_.x + rightUpCorner_.x) / 2;
  double center_y = (leftDownCorner_.y + rightUpCorner_.y) / 2;
  point_t center = {center_x, center_y};
  return {width, height, center};
}
void lebedev::Rectangle::move(const point_t & p)
{
  double center_x = (leftDownCorner_.x + rightUpCorner_.x) / 2;
  double center_y = (leftDownCorner_.y + rightUpCorner_.y) / 2;
  double dx = p.x - center_x;
  double dy = p.y - center_y;
  move(dx, dy);
}
void lebedev::Rectangle::move(double dx, double dy)
{
  leftDownCorner_.x += dx;
  leftDownCorner_.y += dy;
  rightUpCorner_.x += dx;
  rightUpCorner_.y += dy;
}
void lebedev::Rectangle::doScale(double ratio)
{
  double center_x = (leftDownCorner_.x + rightUpCorner_.x) / 2;
  double center_y = (leftDownCorner_.y + rightUpCorner_.y) / 2;
  point_t center = {center_x, center_y};
  rightUpCorner_ = scalePoint(rightUpCorner_, center, ratio);
  leftDownCorner_ = scalePoint(leftDownCorner_, center, ratio);
}
