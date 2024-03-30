#include "base-functions.hpp"
#include <cmath>

lebedev::point_t & lebedev::scalePoint(point_t & p, const point_t & pos, double ratio)
{
  if (p.x >= pos.x)
  {
    p.x = (p.x - pos.x) * ratio + pos.x;
  }
  else
  {
    p.x = pos.x - (pos.x - p.x) * ratio;
  }
  if (p.y >= pos.y)
  {
    p.y = (p.y - pos.y) * ratio + pos.y;
  }
  else
  {
    p.y = pos.y - (pos.y - p.y) * ratio;
  }
  return p;
}

bool lebedev::checkLinesIntersection(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4)
{
  double a = p4.y - p1.y;
  double b = p1.x - p4.x;
  double c = p1.y * p4.x - p1.x * p4.y;
  bool check_intersection = true;
  double res1 = a * p2.x + b * p2.y + c;
  if (res1 != 0)
  {
    res1 = res1 / std::abs(res1);
  }
  double res2 = a * p3.x + b * p3.y + c;
  if (res2 != 0)
  {
    res2 = res2 / std::abs(res2);
  }
  if (res1 == res2 && res1 != 0 && res2 != 0)
  {
    check_intersection = false;
  }
  return check_intersection;
}

lebedev::point_t lebedev::findLinesIntersection(const point_t & p1, const point_t & p2, const point_t & p3, const point_t & p4)
{
  double a1 = p4.y - p1.y;
  double b1 = p1.x - p4.x;
  double c1 = p1.y * p4.x - p1.x * p4.y;
  double a2 = p3.y - p2.y;
  double b2 = p2.x - p3.x;
  double c2 = p2.y * p3.x - p2.x * p3.y;
  double x = (b1 * c2 - b2 * c1) / (a1 * b2 - a2 * b1);
  double y = (a1 * c2 - a2 * c1) / (a2 * b1 - a1 * b2);
  return {x, y};
}

double lebedev::findAreaOfTriangle(const point_t & p1, const point_t & p2, const point_t & p3)
{
  double a = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  double b = std::sqrt((p1.x - p3.x) * (p1.x - p3.x) + (p1.y - p3.y) * (p1.y - p3.y));
  double c = std::sqrt((p2.x - p3.x) * (p2.x - p3.x) + (p2.y - p3.y) * (p2.y - p3.y));
  double halfP = (a + b + c) / 2;
  return std::sqrt(halfP * (halfP - a) * (halfP - b) * (halfP - c));
}
