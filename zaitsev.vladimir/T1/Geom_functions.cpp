#include "Geom_functions.h"
#include <stdexcept>
#include <cmath>
#include "base-types.h"
#include "Shape.h"

double zaitsev::skewProduct(const point_t& vector1, const point_t& vector2)
{
  return vector1.x * vector2.y - vector1.y * vector2.x;
}

bool zaitsev::checkIntersection(const point_t* sections)
{
  point_t vec0 = { sections[1].x - sections[0].x,sections[1].y - sections[0].y };
  point_t vec1 = { sections[2].x - sections[0].x,sections[2].y - sections[0].y };
  point_t vec2 = { sections[3].x - sections[0].x,sections[3].y - sections[0].y };
  if (skewProduct(vec0, vec1) * skewProduct(vec0, vec2) > 0)
  {
    return false;
  }

  vec0 = { sections[3].x - sections[2].x,sections[3].y - sections[2].y };
  vec1 = { sections[0].x - sections[2].x,sections[0].y - sections[2].y };
  vec2 = { sections[1].x - sections[2].x,sections[1].y - sections[2].y };
  if (skewProduct(vec0, vec1) * skewProduct(vec0, vec2) > 0)
  {
    return false;
  }

  if (abs(skewProduct(vec0, vec1)) == 0 && abs(skewProduct(vec0, vec2)) == 0)
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

  return { x,y };
}

void zaitsev::setLineCoeff(const point_t& p1, const point_t& p2, double& a, double& b, double& c)
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

double zaitsev::getAreaOfTriangle(const point_t& p1, const point_t& p2, const point_t& p3)
{
  point_t v1 = { p2.x - p1.x,p2.y - p1.y };
  point_t v2 = { p3.x - p1.x,p3.y - p1.y };
  return abs(skewProduct(v1, v2)) / 2;
}

void zaitsev::scale(Shape* shape, double factor, const point_t& iso_center)
{
  point_t start_pos = shape->getFrameRect().pos;
  shape->move(iso_center);
  point_t iso_center_pos = shape->getFrameRect().pos;
  shape->scale(factor);
  shape->move(factor * (start_pos.x - iso_center_pos.x), factor * (start_pos.y - iso_center_pos.y));
}
