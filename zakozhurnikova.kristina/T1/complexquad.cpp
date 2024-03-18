#include "complexquad.hpp"
#include <cmath>
#include <stdexcept>

bool zakozhurnikova::hasEqualPoints(const point_t* points, size_t size)
{
  for (size_t i = 0; i < size - 1; ++i)
  {
    for (size_t j = i + 1; j < size; ++j)
    {
      if (points[i] == points[j])
      {
        return true;
      }
    }
  }

  return false;
}

bool zakozhurnikova::isPointOnLine(const point_t& p1, const point_t& p2, const point_t& p)
{
  double leftSide = (p.y - p1.y) * (p2.x - p1.x);
  double rightSide = (p.x - p1.x) * (p2.y - p1.y);
  return leftSide == rightSide;
}

bool zakozhurnikova::hasContentPoint(const point_t* points, size_t size)
{
  for (size_t i = 0; i < size - 2; ++i)
  {
    for (size_t j = i + 2; j < size; ++j)
    {
      if (isPointOnLine(points[i], points[i + 1], points[i + 2]))
      {
        return true;
      }
    }
  }
  return false;
}

bool zakozhurnikova::hasIntersection(const point_t* points)
{
  const size_t POINTS_COUNT = 4;
  if (hasEqualPoints(points, POINTS_COUNT)  || hasContentPoint(points, POINTS_COUNT))
  {
    return false;
  }

  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;
  double denominator = (x1 - x2) * (y3 - y4) - (y1 - y2) * (x3 - x4);
  if (std::abs(denominator) <= 1e-6)
  {
    return false;
  }
  double x = ((x1 * y2 - y1 * x2) * (x3 - x4) - (x1 - x2) * (x3 * y4 - y3 * x4)) / denominator;
  double y = ((x1 * y2 - y1 * x2) * (y3 - y4) - (y1 - y2) * (x3 * y4 - y3 * x4)) / denominator;
  const bool IS_DOT_OUT_LINE_FIRST = x < std::min(x1, x2) || x > std::max(x1, x2) || x < std::min(x3, x4) || x > std::max(x3, x4);
  const bool IS_DOT_OUT_LINE_SECOND = y < std::min(y1, y2) || y > std::max(y1, y2) || y < std::min(y3, y4) || y > std::max(y3, y4);
  return  !(IS_DOT_OUT_LINE_FIRST || IS_DOT_OUT_LINE_SECOND);
}


zakozhurnikova::Complexquad::Complexquad(const point_t& p1, const point_t& p2, const point_t& p3, const point_t& p4):
  vertexes_{p1, p2, p3, p4}
{
  if (!hasIntersection(vertexes_))
  {
    throw std::invalid_argument("Incorrect complexquad parameters");
  }
}

zakozhurnikova::point_t getComplexquadCenter(const zakozhurnikova::point_t* points)
{
  double x1 = points[0].x;
  double y1 = points[0].y;
  double x2 = points[1].x;
  double y2 = points[1].y;
  double x3 = points[2].x;
  double y3 = points[2].y;
  double x4 = points[3].x;
  double y4 = points[3].y;
  double determinant = (x2 - x1) * (y4 - y3) - (x4 - x3) * (y2 - y1);
  double determinantX = (x2 - x1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (x4 - x3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  double determinantY = (y2 - y1) * (y3 * (x4 - x3) - x3 * (y4 - y3)) - (y4 - y3) * (y1 * (x2 - x1) - x1 * (y2 - y1));
  zakozhurnikova::point_t center = {-determinantX / determinant, -determinantY / determinant};
  return center;
}

double zakozhurnikova::Complexquad::getArea() const
{
  point_t center = getComplexquadCenter(vertexes_);

  double a1 = getDistance(vertexes_[0], center);
  double b1 = getDistance(vertexes_[3], center);
  double c1 = getDistance(vertexes_[0], vertexes_[3]);
  double s1 = (a1 + b1 + c1) / 2.0;
  double area1 = std::sqrt(s1 * (s1 - a1) * (s1 - b1) * (s1 - c1));

  double a2 = getDistance(vertexes_[1], center);
  double b2 = getDistance(vertexes_[2], center);
  double c2 = getDistance(vertexes_[1], vertexes_[2]);
  double s2 = (a2 + b2 + c2) / 2.0;
  double area2 = std::sqrt(s2 * (s2 - a2) * (s2 - b2) * (s2 - c2));

  return area1 + area2;
}

zakozhurnikova::rectangle_t zakozhurnikova::Complexquad::getFrameRect() const
{
  double x1 = vertexes_[0].x;
  double y1 = vertexes_[0].y;
  double x2 = vertexes_[1].x;
  double y2 = vertexes_[1].y;
  double x3 = vertexes_[2].x;
  double y3 = vertexes_[2].y;
  double x4 = vertexes_[3].x;
  double y4 = vertexes_[3].y;
  double minX = std::min(std::min(x1, x2), std::min(x3, x4));
  double minY = std::min(std::min(y1, y2), std::min(y3, y4));
  double maxX = std::max(std::max(x1, x2), std::max(x3, x4));
  double maxY = std::max(std::max(y1, y2), std::max(y3, y4));
  double width = maxX - minX;
  double height = maxY - minY;
  point_t center = {(maxX + minX) / 2.0, (maxY + minY) / 2.0};
  return rectangle_t{width, height, center};
}

void zakozhurnikova::Complexquad::move(const point_t& p)
{
  point_t center = getComplexquadCenter(vertexes_);
  point_t shift(p - center);
  vertexes_[0] += shift;
  vertexes_[1] += shift;
  vertexes_[2] += shift;
  vertexes_[3] += shift;
}

void zakozhurnikova::Complexquad::move(double dx, double dy)
{
  point_t shift = {dx, dy};
  vertexes_[0] += shift;
  vertexes_[1] += shift;
  vertexes_[2] += shift;
  vertexes_[3] += shift;
}

void zakozhurnikova::Complexquad::unsafeScale(double k)
{
  point_t center = getComplexquadCenter(vertexes_);
  vertexes_[0] = scaleShift(k, vertexes_[0], center);
  vertexes_[1] = scaleShift(k, vertexes_[1], center);
  vertexes_[2] = scaleShift(k, vertexes_[2], center);
  vertexes_[3] = scaleShift(k, vertexes_[3], center);
}
