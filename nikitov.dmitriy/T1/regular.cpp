#include "regular.hpp"
#include <cmath>
#include <limits>
#include <stdexcept>

nikitov::Regular::Regular(const point_t& first, const point_t& second, const point_t& third):
  first_(first),
  second_(second),
  third_(third)
{
  double firstLine = std::pow(first_.x - second_.x, 2.0) + std::pow(first_.y - second_.y, 2.0);
  double secondLine = std::pow(third_.x - second_.x, 2.0) + std::pow(third_.y - second_.y, 2.0);
  double thirdLine = std::pow(first_.x - third_.x, 2.0) + std::pow(first_.y - third_.y, 2.0);

  bool isNotExists = !(firstLine + secondLine == thirdLine);
  isNotExists = isNotExists && !(secondLine + thirdLine == firstLine);
  isNotExists = isNotExists || (std::max(sqrt(firstLine), std::sqrt(thirdLine)) > std::sqrt(secondLine) * 2);
  if (isNotExists)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

double nikitov::Regular::getArea() const
{
  const double PI = 3.141592653589793;
  double firstLine = std::sqrt(pow(first_.x - second_.x, 2.0) + std::pow(first_.y - second_.y, 2.0));
  double thirdLine = std::sqrt(pow(first_.x - third_.x, 2.0) + std::pow(first_.y - third_.y, 2.0));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = std::round(-2.0 * PI / (std::asin(inRadius / circumRadius) * 2.0 - PI));

  double a = 2.0 * circumRadius * std::sin(PI / n);
  return 0.5 * n * a * inRadius;
}

nikitov::rectangle_t nikitov::Regular::getFrameRect() const
{
  const double PI = 3.141592653589793;
  double firstLine = std::sqrt(pow(first_.x - second_.x, 2.0) + std::pow(first_.y - second_.y, 2.0));
  double thirdLine = std::sqrt(pow(first_.x - third_.x, 2.0) + std::pow(first_.y - third_.y, 2.0));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  size_t n = std::round(-2.0 * PI / (std::asin(inRadius / circumRadius) * 2.0 - PI));
  double a = 2.0 * circumRadius * std::sin(PI / n);

  double maxX = std::numeric_limits< double >::lowest();
  double maxY = maxX;
  double minX = std::numeric_limits< double >::max();
  double minY = minX;

  point_t point;
  if (circumRadius == firstLine)
  {
    point = second_;
  }
  else
  {
    point = third_;
  }

  point.x = point.x - first_.x;
  point.y = point.y - first_.y;
  double angle = 2.0 * asin(a / 2.0  / circumRadius);
  for (size_t i = 0; i != n; ++i)
  {
    double x = point.x;
    double y = point.y;
    point.x = x * std::cos(angle) - y * std::sin(angle);
    point.y = y * std::cos(angle) + x * std::sin(angle);
    maxX = std::max(maxX, point.x);
    minX = std::min(minX, point.x);
    maxY = std::max(maxY, point.y);
    minY = std::min(minY, point.y);
  }
  return { maxX - minX, maxY - minY, first_ };
}

void nikitov::Regular::move(const point_t& point)
{
  double dx = point.x - first_.x;
  double dy = point.y - first_.y;
  move(dx, dy);
}

void nikitov::Regular::move(double dx, double dy)
{
  first_.x += dx;
  first_.y += dy;
  second_.x += dx;
  second_.y += dy;
  third_.x += dx;
  third_.y += dy;
}

void nikitov::Regular::doScale(double ratio)
{
  second_.x = first_.x + (second_.x - first_.x) * ratio;
  second_.y = first_.y + (second_.y - first_.y) * ratio;
  third_.x = first_.x + (third_.x - first_.x) * ratio;
  third_.y = first_.y + (third_.y - first_.y) * ratio;
}

nikitov::Shape* nikitov::Regular::clone() const
{
  return new Regular(first_, second_, third_);
}
