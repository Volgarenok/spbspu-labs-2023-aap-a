#include "geometryFunc.hpp"
#include <cmath>
#include <stdexcept>

zakozhurnikova::point_t zakozhurnikova::scaleShift(double k, const point_t& p1, const point_t& p2)
{
  double shiftX = p2.x + k * (p1.x - p2.x);
  double shiftY = p2.y + k * (p1.y - p2.y);
  return point_t{shiftX, shiftY};
}

double zakozhurnikova::getDistance(const point_t& p1, const point_t& p2)
{
  double distance = std::sqrt((p1.x - p2.x) * (p1.x - p2.x) + (p1.y - p2.y) * (p1.y - p2.y));
  return distance;
}

void zakozhurnikova::operator+=(point_t& dest, const point_t& src)
{
  dest.x += src.x;
  dest.y += src.y;
}

zakozhurnikova::point_t zakozhurnikova::operator+(const point_t& p1, const point_t& p2)
{
  return point_t{p1.x + p2.x, p1.y + p2.y};
}

zakozhurnikova::point_t zakozhurnikova::operator-(const point_t& p1, const point_t& p2)
{
  return point_t{p1.x - p2.x, p1.y - p2.y};
}

zakozhurnikova::point_t zakozhurnikova::operator*(const point_t& p1, double k)
{
  return point_t{p1.x * k, p1.y * k};
}

zakozhurnikova::point_t zakozhurnikova::operator/(const point_t& p1, double k)
{
  if (k == 0.0)
  {
    throw std::invalid_argument("Division by ZERO.");
  }
  return point_t{p1.x / k, p1.y / k};
}

bool zakozhurnikova::operator==(const point_t& p1, const point_t& p2)
{
  return p1.x == p2.x && p1.y == p2.y;
}
