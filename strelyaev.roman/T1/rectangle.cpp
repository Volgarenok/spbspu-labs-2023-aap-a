#include "rectangle.hpp"
#include <cmath>
#include <stdexcept>

strelyaev::Rectangle::Rectangle(point_t p1, point_t p2):
  p1_(p1),
  p2_(p2)
{
  if (p1_.x >= p2_.x || p1_.y >= p2_.y)
  {
    throw std::invalid_argument("Invalid points for RECTANGLE");
  }
}

double strelyaev::Rectangle::getArea() const
{
  double height = std::abs(p1_.y - p2_.y);
  double width = std::abs(p1_.x - p2_.x);
  return height * width;
}

strelyaev::rectangle_t strelyaev::Rectangle::getFrameRect() const
{
  point_t center({(p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2});
  double height = std::abs(p1_.y - p2_.y);
  double width = std::abs(p1_.x - p2_.x);
  rectangle_t r1 = {width, height, center};
  return r1;
}

void strelyaev::Rectangle::move(const point_t new_center)
{
  point_t center({(p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2});
  double offset_x = new_center.x - center.x;
  double offset_y = new_center.y - center.y;
  this->move(offset_x, offset_y);
}

void strelyaev::Rectangle::move(double dx, double dy)
{
  point_t center({(p1_.x + p2_.x) / 2, (p1_.y + p2_.y) / 2});
  center.x += dx;
  center.y += dy;
  point_t* points[] = {&p1_, &p2_};
  for (size_t i = 0; i < 2; i++)
  {
    points[i]->x += dx;
    points[i]->y += dy;
  }
}

void strelyaev::Rectangle::unsafeScale(double k)
{
  double width = std::abs(p1_.x - p2_.x);
  double height = std::abs(p1_.y - p2_.y);

  double new_width = width * k;
  double new_height = height * k;

  double offset_x = (new_width - width) / 2.0;
  double offset_y = (new_height - height) / 2.0;
  p1_.x -= offset_x;
  p1_.y -= offset_y;
  p2_.x += offset_x;
  p2_.y += offset_y;
}
