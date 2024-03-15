#include "checkTriangle.hpp"
#include <cmath>
#include <stdexcept>

void marishin::checkTriangle(const point_t& first, const point_t& second, const point_t& third)
{
  const point_t& p1 = first;
  const point_t& p2 = second;
  const point_t& p3 = third;

  double ab = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  double ac = std::sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
  double bc = std::sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));

  if (ab >= ac + bc || bc >= ab + ac || ac >= ab + bc)
  {
    throw std::invalid_argument("Irregular triangle");
  }
}

double marishin::getAreaTriangle(const point_t& first, const point_t& second, const point_t& third)
{
  const point_t& p1 = first;
  const point_t& p2 = second;
  const point_t& p3 = third;

  double ab = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  double ac = std::sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
  double bc = std::sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
  double abc = (ab + bc + ac) / 2;
  return std::sqrt(abc * (abc - ab) * (abc - bc) * (abc - ac));
}

marishin::rectangle_t marishin::getFrameRectTriangle(const point_t& first, const point_t& second, const point_t& third)
{
  const point_t& p1 = first;
  const point_t& p2 = second;
  const point_t& p3 = third;

  double height = (std::max(p1.y, (std::max(p2.y, p3.y))) - (std::min(p1.y, (std::min(p2.y, p3.y)))));
  double width = (std::max(p1.x, (std::max(p2.x, p3.x))) - (std::min(p1.x, (std::min(p2.x, p3.x)))));
  point_t pos = { (std::min(p1.x, (std::min(p2.x, p3.x)))) + width / 2, (std::min(p1.y, (std::min(p2.y, p3.y)))) + height / 2 };
  return { pos, width, height };
}

marishin::point_t marishin::scaleCorner(point_t& corner, point_t& pos, double factor)
{
  corner.x = factor * (corner.x - pos.x) + pos.x;
  corner.y = factor * (corner.y - pos.y) + pos.y;
  return corner;
}
