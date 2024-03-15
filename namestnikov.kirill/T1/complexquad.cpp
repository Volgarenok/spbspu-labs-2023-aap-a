#include "complexquad.hpp"
#include <stdexcept>
#include <algorithm>
#include "geometric_functions.hpp"
#include "base-types.hpp"

namestnikov::Complexquad::Complexquad(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4):
  points_{p1, p2, p3, p4}
{
  if (!checkIntersectionOfTwoLines(p1, p2, p3, p4))
  {
    throw std::invalid_argument("Lines are parallel in complexquad");
  }
  point_t points[4] = {p1, p2, p3, p4};
  for (size_t i = 0; i < 4; ++i)
  {
    for (size_t j = i + 1; j < 4; ++j)
    {
      if ((points[i].x == points[j].x) && (points[i].y == points[j].y))
      {
        throw std::invalid_argument("There shouldn't be 2 same points in complexquad");
      }
    }
  }
}

double namestnikov::Complexquad::getArea() const
{
  point_t centerPoint = getIntersectionOfTwoLines(points_[0], points_[1], points_[2], points_[3]);
  double square = getAreaOfTriangle(points_[0], points_[3], centerPoint);
  square += getAreaOfTriangle(points_[1], points_[2], centerPoint);
  return square;
}

namestnikov::rectangle_t namestnikov::Complexquad::getFrameRect() const
{
  double mostLowPoint = points_[0].y;
  double mostHighPoint = points_[0].y;
  double mostLeftPoint = points_[0].x;
  double mostRightPoint = points_[0].x;
  for (size_t i = 1; i < 4; ++i)
  {
    mostLowPoint = std::min(mostLowPoint, points_[i].y);
    mostHighPoint = std::max(mostHighPoint, points_[i].y);
    mostLeftPoint = std::min(mostLeftPoint, points_[i].x);
    mostRightPoint = std::max(mostRightPoint, points_[i].x);
  }
  double width = std::abs(mostRightPoint - mostLeftPoint);
  double height = std::abs(mostHighPoint - mostLowPoint);
  point_t position = {mostLeftPoint + (width / 2), mostLowPoint + (height / 2)};
  return {width, height, position};
}

namestnikov::point_t namestnikov::Complexquad::getCenter() const
{
  return getIntersectionOfTwoLines(points_[0], points_[1], points_[2], points_[3]);
}

void namestnikov::Complexquad::move(const point_t & p)
{
  point_t centerPoint = getIntersectionOfTwoLines(points_[0], points_[1], points_[2], points_[3]);
  const double dx = p.x - centerPoint.x;
  const double dy = p.y - centerPoint.y;
  move(dx, dy);
}

void namestnikov::Complexquad::move(const double dx, const double dy)
{
  for (size_t i = 0; i < 4; ++i)
  {
    movePoint(points_[i], dx, dy);
  }
}

void namestnikov::Complexquad::unsafeScale(const double coefficient)
{
  point_t centerPoint = getIntersectionOfTwoLines(points_[0], points_[1], points_[2], points_[3]);
  for (size_t i = 0; i < 4; ++i)
  {
    scalePoint(points_[i], centerPoint, coefficient);
  }
}
