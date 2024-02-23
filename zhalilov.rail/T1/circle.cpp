#include "circle.hpp"

#include <stdexcept>

zhalilov::Circle::Circle(const point_t &center, double radius):
  m_center(center),
  m_radius(radius)
{
  if (m_radius <= 0.0)
  {
    throw std::invalid_argument("circle radius should be more than zero");
  }
}

double zhalilov::Circle::getArea() const
{
  return 3.14 * m_radius * m_radius;
}

zhalilov::rectangle_t zhalilov::Circle::getFrameRect() const
{
  return { m_radius * 2, m_radius * 2, m_center };
}

void zhalilov::Circle::move(const point_t &point)
{
  m_center = point;
}

void zhalilov::Circle::move(const double dx, const double dy)
{
  m_center.x += dx;
  m_center.y += dy;
}

void zhalilov::Circle::unsafeScale(const double ratio)
{
  m_radius *= ratio;
}
