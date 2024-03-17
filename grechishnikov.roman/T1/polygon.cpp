#include "polygon.hpp"
#include <stdexcept>
#include <algorithm>
#include "triangle.hpp"
#include "pointLogic.hpp"

grechishnikov::Polygon::Polygon(const point_t* points, size_t size):
  points_(new point_t[size]),
  size_(size)
{
  if (size < 3)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (Not enough arguments for Polygon)");
  }
  for (size_t i = 0; i < size; i++)
  {
    points_[i] = points[i];
  }
  try
  {
    for (size_t i = 2; i < size; i++)
    {
      Triangle triangle(points[0], points[i - 1], points[i]);
    }
  }
  catch (const std::logic_error& e)
  {
    delete[] points_;
    throw std::invalid_argument("Invalid parameters (some points are in a line)");
  }
}

grechishnikov::Polygon::~Polygon()
{
  delete[] points_;
}

double grechishnikov::Polygon::getArea() const
{
  double result = 0;
  for (size_t i = 2; i < size_; i++)
  {
    Triangle triangle(points_[0], points_[i - 1], points_[i]);
    result += triangle.getArea();
  }
  return result;
}

grechishnikov::rectangle_t grechishnikov::Polygon::getFrameRect() const
{
  return getFrameRectGeneral(points_, size_);
}

void grechishnikov::Polygon::move(const point_t& pos)
{
  point_t aPos = getAveragePoint(points_, size_);
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Polygon::move(double dx, double dy)
{
  movePoints(points_, size_, dx, dy);
}

void grechishnikov::Polygon::unsafeScale(double rate)
{
  unsafeScalePoints(points_, size_, rate);
}
