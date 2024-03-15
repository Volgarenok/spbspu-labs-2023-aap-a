#include "diamond.hpp"
#include "triangle.hpp"
#include "data_process.hpp"

ishmuratov::Diamond::Diamond(const point_t & point1, const point_t & point2, const point_t & point3):
  corners_{ point1, point2, point3 }
{
  if (triangleArea(corners_[0], corners_[1], corners_[2]) == 0)
  {
    throw std::invalid_argument("This is not a triangle!");
  }
  bool diagx = (corners_[0].x != corners_[1].x) && (corners_[0].x != corners_[2].x) && (corners_[1].x != corners_[2].x);
  bool diagy = (corners_[0].y != corners_[1].y) && (corners_[0].y != corners_[2].y) && (corners_[1].y != corners_[2].y);
  if (diagx || diagy)
  {
    throw std::invalid_argument("Diagonals of diamond must be parallel to axis!");
  }
}

ishmuratov::Diamond::~Diamond() = default;

double ishmuratov::Diamond::getArea() const
{
  Triangle tri = { corners_[0], corners_[1], corners_[2] };
  return tri.getArea() * 4;
}

ishmuratov::rectangle_t ishmuratov::Diamond::getFrameRect() const
{
  Triangle tri = { corners_[0], corners_[1], corners_[2] };
  rectangle_t frameRect = tri.Triangle::getFrameRect();
  frameRect.width *= 2;
  frameRect.height *= 2;
  frameRect.pos = diamondCenter(corners_[0], corners_[1], corners_[2]);
  return frameRect;
}

void ishmuratov::Diamond::move(point_t position)
{
  point_t center = diamondCenter(corners_[0], corners_[1], corners_[2]);
  double dx = position.x - center.x;
  double dy = position.y - center.y;
  move(dx, dy);
}

void ishmuratov::Diamond::move(double dx, double dy)
{
  for (size_t i = 0; i < 3; ++i)
  {
    corners_[i] = { corners_[i].x + dx, corners_[i].y + dy };
  }
}

void ishmuratov::Diamond::scale(double factor)
{
  if (factor <= 0)
  {
    throw std::runtime_error("Invalid factor!");
  }
  point_t center = diamondCenter(corners_[0], corners_[1], corners_[2]);
  scaleTriangle(corners_, center, factor);
}
