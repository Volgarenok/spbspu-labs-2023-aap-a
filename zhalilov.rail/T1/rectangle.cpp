#include "rectangle.hpp"

#include <stdexcept>

zhalilov::Rectangle::Rectangle(const point_t &leftCorner, const point_t &rightCorner):
  m_leftCorner(leftCorner),
  m_rightCorner(rightCorner)
{
  if (m_leftCorner.x >= m_rightCorner.x || m_leftCorner.y >= m_rightCorner.y)
  {
    throw std::invalid_argument("invalid rectangle source");
  }
}

double zhalilov::Rectangle::getArea() const
{
  rectangle_t rect = getFrameRect();
  return rect.width * rect.height;
}

zhalilov::rectangle_t zhalilov::Rectangle::getFrameRect() const
{
  double width = m_rightCorner.x - m_leftCorner.x;
  double height = m_rightCorner.y - m_leftCorner.y;
  point_t pos = { m_leftCorner.x + width / 2.0, m_leftCorner.y + height / 2.0 };
  return { width, height, pos };
}

void zhalilov::Rectangle::move(const point_t &point)
{
  rectangle_t rect = getFrameRect();
  move(point.x - rect.pos.x, point.y - rect.pos.y);
}

void zhalilov::Rectangle::move(const double dx, const double dy)
{
  m_leftCorner.x += dx;
  m_leftCorner.y += dy;
  m_rightCorner.x += dx;
  m_rightCorner.y += dy;
}

void zhalilov::Rectangle::unsafeScale(const double ratio)
{
  rectangle_t rect = getFrameRect();
  m_leftCorner.x = rect.pos.x - (rect.pos.x - m_leftCorner.x) * ratio;
  m_leftCorner.y = rect.pos.y - (rect.pos.y - m_leftCorner.y) * ratio;
  m_rightCorner.x = rect.pos.x + (m_rightCorner.x - rect.pos.x) * ratio;
  m_rightCorner.y = rect.pos.y + (m_rightCorner.y - rect.pos.y) * ratio;
}
