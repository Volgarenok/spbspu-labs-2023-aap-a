#include "rectangle.hpp"

#include <stdexcept>

#include "definedata.hpp"

gladyshev::Rectangle::Rectangle(const point_t& p1, const point_t& p2):
  p1FrameRec_(p1),
  p2FrameRec_(p2)
{
  if ((p1.x == p2.x) || (p1.y == p2.y) || (p2.x < p1.x) || (p2.y < p1.y))
  {
    throw std::invalid_argument("bad rectangle coords");
  }
}

gladyshev::Rectangle::~Rectangle() = default;

double gladyshev::Rectangle::getArea() const
{
  return std::abs((p2FrameRec_.x - p1FrameRec_.x) * (p2FrameRec_.y - p1FrameRec_.y));
}

void gladyshev::Rectangle::move(double dx, double dy)
{
  p1FrameRec_.x += dx;
  p2FrameRec_.x += dx;
  p1FrameRec_.y += dy;
  p2FrameRec_.y += dy;
}

void gladyshev::Rectangle::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}

gladyshev::rectangle_t gladyshev::Rectangle::getFrameRect() const
{
  double height = std::abs(p1FrameRec_.y - p2FrameRec_.y);
  double width = std::abs(p1FrameRec_.x - p2FrameRec_.x);
  point_t pos = { (p1FrameRec_.x + p2FrameRec_.x) / 2, (p1FrameRec_.y + p2FrameRec_.y) / 2 };
  return { pos, width, height };
}

void gladyshev::Rectangle::unsafeScale(double factor)
{
  rectangle_t frameRect = getFrameRect();
  scalePoint(p1FrameRec_, factor, frameRect);
  scalePoint(p2FrameRec_, factor, frameRect);
}
