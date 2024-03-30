#include "geometric_functions.hpp"
#include <stdexcept>
#include <cmath>
#include "base-types.hpp"
#include "shape.hpp"

void setLineCoeff(zaitsev::point_t p1, zaitsev::point_t p2, double& a, double& b, double& c);
double skewProduct(zaitsev::point_t vector1, zaitsev::point_t vector2);

double skewProduct(zaitsev::point_t vector1, zaitsev::point_t vector2)
{
  return vector1.x * vector2.y - vector1.y * vector2.x;
}

bool zaitsev::checkIntersection(const point_t* sections)
{
  point_t vec10 = sections[1] - sections[0];
  point_t vec20 = sections[2] - sections[0];
  point_t vec30 = sections[3] - sections[0];
  if (skewProduct(vec10, vec20) * skewProduct(vec10, vec30) >= 0)
  {
    return false;
  }

  vec10 = sections[3] - sections[2];
  vec20 = sections[0] - sections[2];
  vec30 = sections[1] - sections[2];
  if (skewProduct(vec10, vec20) * skewProduct(vec10, vec30) >= 0)
  {
    return false;
  }

  return true;
}

zaitsev::point_t zaitsev::findIntersection(const point_t* sections)
{
  double a1 = 0, a2 = 0;
  double b1 = 0, b2 = 0;
  double c1 = 0, c2 = 0;

  setLineCoeff(sections[0], sections[1], a1, b1, c1);
  setLineCoeff(sections[2], sections[3], a2, b2, c2);

  if (a1 * b2 == a2 * b1)
  {
    throw std::invalid_argument("Lines are parallel");
  }

  double y = 0;
  double x = 0;
  if (a1 == 0)
  {
    y = -c1;
    x = -y * b2 - c2;
  }
  else if (a2 == 0)
  {
    y = -c2;
    x = -y * b1 - c1;
  }
  else
  {
    y = b1 == b2 ? 0 : (c2 - c1) / (b1 - b2);
    x = -y * b2 - c2;
  }

  return { x, y };
}

void setLineCoeff(zaitsev::point_t p1, zaitsev::point_t p2, double& a, double& b, double& c)
{
  if (p1.x == p2.x)
  {
    a = 1;
    b = 0;
    c = -p1.x;
    return;
  }
  if (p1.y == p2.y)
  {
    a = 0;
    b = 1;
    c = -p1.y;
    return;
  }

  a = 1;
  b = (p2.x - p1.x) / (p1.y - p2.y);
  c = -(p1.x * a + p1.y * b);
}

double zaitsev::getAreaOfTriangle(point_t p1, point_t p2, point_t p3)
{
  return std::fabs(skewProduct(p2 - p1, p3 - p1)) / 2;
}

void zaitsev::changeRectangleBounds(point_t& left_corner, point_t& right_corner, point_t new_pt)
{
  left_corner.x = std::min(left_corner.x, new_pt.x);
  left_corner.y = std::min(left_corner.y, new_pt.y);
  right_corner.x = std::max(right_corner.x, new_pt.x);
  right_corner.y = std::max(right_corner.y, new_pt.y);
}

zaitsev::rectangle_t zaitsev::transformRectangleBounds(point_t left_corner, point_t right_corner)
{
  point_t size = right_corner - left_corner;
  point_t pos = (left_corner + right_corner) / 2;
  return { size.x, size.y, pos };
}
