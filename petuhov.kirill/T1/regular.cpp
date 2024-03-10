#include "regular.hpp"
#include <stdexcept>
#include <cmath>

petuhov::Regular::Regular(const petuhov::point_t &pos, float radius, int vertexCount): center_(pos), radius_(0.0f), vertexCount_(0)
{
  if (radius > 0.0f)
  {
    radius_ = radius;
  }
  else
  {
    throw std::invalid_argument("Invalid radius");
  }
  if (vertexCount > 2)
  {
    vertexCount_ = vertexCount;
  }
  else
  {
    throw std::invalid_argument("Invalid vertex count");
  }
}

float petuhov::Regular::getArea() const
{
  return (vertexCount_ * radius_ * radius_ * sin(3.14 / vertexCount_)) / 2;
}

petuhov::rectangle_t petuhov::Regular::getFrameRect() const
{
  float width = 2 * radius_;
  float height = 2 * radius_;
  return {center_, width, height};
}

void petuhov::Regular::move(const petuhov::point_t &pos)
{
  center_ = pos;
}

void petuhov::Regular::move(float dx, float dy)
{
  center_.x += dx;
  center_.y += dy;
}

void petuhov::Regular::scale(float factor)
{
  if (factor <= 0.0f)
  {
    throw std::invalid_argument("Invalid factor");
  }
  radius_ *= factor;
}
