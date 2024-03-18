#include "circle.hpp"
#include <stdexcept>
#include <cmath>

petuhov::Circle::Circle(const point_t &center, float radius): center_(center), radius_(0.0f)
{
  if (radius > 0.0f)
  {
    radius_ = radius;
  }
  else
  {
    throw std::invalid_argument("Invalid radius");
  }
}

float petuhov::Circle::getArea() const
{
  return M_PI * radius_ * radius_;
}

petuhov::rectangle_t petuhov::Circle::getFrameRect() const
{
  return {center_, radius_ * 2, radius_ * 2};
}

void petuhov::Circle::move(const petuhov::point_t &pos)
{
  center_ = pos;
}

void petuhov::Circle::move(float dx, float dy)
{
  center_.x += dx;
  center_.y += dy;
}

void petuhov::Circle::scale(const petuhov::point_t &scale_center, float factor)
{
  if (factor <= 0.0f)
  {
    throw std::invalid_argument("Invalid factor");
  }

  float dx = center_.x - scale_center.x;
  float dy = center_.y - scale_center.y;
  radius_ *= factor;
  center_.x = scale_center.x + dx * factor;
  center_.y = scale_center.y + dy * factor;
}
