#include "triangle.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>
#include "pointLogic.hpp"

double findAreaOfTri(const grechishnikov::point_t& a, const grechishnikov::point_t& b, const grechishnikov::point_t& c);

grechishnikov::Triangle::Triangle(const point_t& a, const point_t& b, const point_t& c):
  points_{ a, b, c },
  size_(3)
{
  if (findAreaOfTri(a, b, c) == 0)
  {
    throw std::invalid_argument("Invalid parameters (Points don't form a triangle)");
  }
}

double grechishnikov::Triangle::getArea() const
{
   return findAreaOfTri(points_[0], points_[1], points_[2]);
}

grechishnikov::rectangle_t grechishnikov::Triangle::getFrameRect() const
{
  return getFrameRectGeneral(points_, 3);
}

void grechishnikov::Triangle::move(const point_t& pos)
{
  point_t aPos = getAveragePoint(points_, 3);
  move(pos.x - aPos.x, pos.y - aPos.y);
}

void grechishnikov::Triangle::move(double dx, double dy)
{
  movePoints(points_, size_, dx, dy);
}

void grechishnikov::Triangle::unsafeScale(double rate)
{
  unsafeScalePoints(points_, size_, rate);
}

double findAreaOfTri(const grechishnikov::point_t& a, const grechishnikov::point_t& b, const grechishnikov::point_t& c)
{
  double sq = ((b.x - a.x) * (c.y - a.y) - (c.x - a.x) * (b.y - a.y)) / 2;
  sq = std::abs(sq);
  return sq;
}
