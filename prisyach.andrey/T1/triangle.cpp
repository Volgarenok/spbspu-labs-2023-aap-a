#include "triangle.h"
#include <stdexcept>
#include <cmath>
#include "isoscale.h"

Shape* inputTriangle(std::istream& input)
{
  double x1 = 0.0;
  double y1 = 0.0;
  double x2 = 0.0;
  double y2 = 0.0;
  double x3 = 0.0;
  double y3 = 0.0;
  input >> x1 >> y1 >> x2 >> y2 >> x3 >> y3;
  if (!input)
  {
    throw std::logic_error("error");
  }
  return new Triangle(point_t{x1, y1}, point_t{x2, y2}, point_t{x3, y3});
}

double findSide(point_t p1, point_t p2)
{
  return std::pow((std::pow((p2.x - p1.x), 2) + std::pow((p2.y - p1.y), 2)), 0.5);
}

Triangle::Triangle(point_t pos1, point_t pos2, point_t pos3):
  points_{pos1, pos2, pos3}
{
  double side1 = findSide(pos1, pos2);
  double side2 = findSide(pos2, pos3);
  double side3 = findSide(pos3, pos1);
  if (((side3 + side2) <= side1) || ((side2 + side1) <= side3) || ((side3 + side1) <= side2))
  {
    throw std::invalid_argument("wrong triangle");
  }
}

double Triangle::getArea() const
{
  double firstpart = (points_[1].x - points_[0].x) * (points_[2].y - points_[0].y);
  double secondpart = (points_[2].x - points_[0].x) * (points_[1].y - points_[0].y);
  return std::abs(0.5 * (firstpart - secondpart));
}

rectangle_t Triangle::getFrameRect() const
{
  double maxx = 0.0;
  double maxy = 0.0;
  double minx = 0.0;
  double miny = 0.0;
  for (size_t i = 0; i < 2; i++)
  {
    maxx = std::max(maxx, std::max(points_[i].x, points_[i + 1].x));
    maxy = std::max(maxy, std::max(points_[i].y, points_[i + 1].y));
    minx = std::min(minx, std::min(points_[i].x, points_[i + 1].x));
    miny = std::min(miny, std::min(points_[i].y, points_[i + 1].y));
  }
  return makeFrame(point_t{minx, miny}, point_t{maxx, maxy});
}

point_t Triangle::findCenterOfTriangle() const
{
  double pos1 = (points_[0].x + points_[1].x + points_[2].x) / 3;
  double pos2 = (points_[0].y + points_[1].y + points_[2].y) / 3;
  return (point_t {pos1, pos2});
}

void Triangle::move(point_t point)
{
  point_t center = findCenterOfTriangle();
  move(point.x - center.x, point.y - center.y);
}

point_t operator+(const point_t& pos1, const point_t& pos2)
{
  point_t pos{pos1.x + pos2.x, pos1.y + pos2.y};
  return pos;
}

void Triangle::move(double dx, double dy)
{
  point_t delta{dx, dy};
  for (size_t i = 0; i < 3; i++)
  {
    points_[i] = points_[i] + delta;
  }
}

void Triangle::scale(double k) noexcept
{
  point_t center = findCenterOfTriangle();
  for (size_t i = 0; i < 3; i++)
  {
    isoScaleForPoint(points_[i], center, k);
  }
}

Shape* Triangle::clone() const
{
  return new Triangle(points_[0], points_[1], points_[2]);
}
