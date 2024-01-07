#include "calculatetriangle.hpp"

double marishin::calculateDistance(const point_t& p1, const point_t& p2)
{
  return sqrt(pow(p2.x - p1.x, 2) + pow(p2.y - p1.y, 2));
}

bool marishin::isTriangleExist(const point_t& p1, const point_t& p2, const point_t& p3)
{
  double a = calculateDistance(p1, p2);
  double b = calculateDistance(p2, p3);
  double c = calculateDistance(p3, p1);

  return (a + b > c) && (b + c > a) && (c + a > b);
}

double marishin::calculateTriangleArea(const point_t& p1, const point_t& p2, const point_t& p3)
{
  return 0.5 * abs((p1.x * (p2.y - p3.y) + p2.x * (p3.y - p1.y) + p3.x * (p1.y - p2.y)));
}
