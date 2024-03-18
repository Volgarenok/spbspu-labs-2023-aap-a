#include "diamond.hpp"
#include <stdexcept>
#include "base-types.hpp"
#include "triangle.hpp"
#include "geom_func.hpp"

erohin::Diamond::Diamond(point_t corner1, point_t corner2, point_t corner3):
  frameRect_{ findDiamondFrameRect(corner1, corner2, corner3) }
{
  if (frameRect_.width * frameRect_.height == 0.0)
  {
    throw std::invalid_argument("Diamond sides are not parallel to the axes");
  }
}

erohin::Diamond::~Diamond() = default;

double erohin::Diamond::getArea() const
{
  return (frameRect_.width * frameRect_.height) / 2;
}

erohin::rectangle_t erohin::Diamond::getFrameRect() const
{
  return frameRect_;
}

void erohin::Diamond::move(double dx, double dy)
{
  frameRect_.pos.x += dx;
  frameRect_.pos.y += dy;
}

void erohin::Diamond::move(point_t point)
{
  frameRect_.pos = point;
}

void erohin::Diamond::unsafeScale(double ratio)
{
  frameRect_.width *= ratio;
  frameRect_.height *= ratio;
}

erohin::Shape* erohin::Diamond::clone() const
{
  rectangle_t framRect = getFrameRect();
  point_t corner1 = framRect.pos;
  point_t corner2 = {framRect.pos.x, framRect.pos.y + framRect.height/ 2.0};
  point_t corner3 = {framRect.pos.x + framRect.width / 2.0 , framRect.pos.y};
  Shape* shape = new Diamond(corner1, corner2, corner3);
  return shape;
}
