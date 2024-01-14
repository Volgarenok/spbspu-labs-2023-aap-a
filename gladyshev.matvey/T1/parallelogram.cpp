#include <stdexcept>

#include "parallelogram.hpp"

gladyshev::Parallelogram::Parallelogram(const point_t& p1, const point_t& p2, const point_t& p3):
  p1par_(p1),
  p2par_(p2),
  p3par_(p3),
  p1FramePar_{ std::min(p1.x, std::min(p2.x, std::min(p3.x, p1.x - p2.x + p3.x))), std::min(p1.y, p3.y) },
  p2FramePar_{ std::max(p1.x, std::max(p2.x, std::max(p3.x, p1.x - p2.x + p3.x))), std::max(p1.y, p3.y) },
  kf_(1)
{}

gladyshev::Parallelogram::~Parallelogram()
{}

double gladyshev::Parallelogram::getArea() const
{
  return std::abs((p1par_.y - p3par_.y) * (p1par_.x - p2par_.x)) * kf_;
}

gladyshev::rectangle_t gladyshev::Parallelogram::getFrameRect() const
{
  rectangle_t frameRect;
  frameRect.width = std::abs(p1FramePar_.x - p2FramePar_.x);
  frameRect.height = std::abs(p1FramePar_.y - p2FramePar_.y);
  frameRect.pos = { (p1FramePar_.x + p2FramePar_.x) / 2, (p1FramePar_.y + p2FramePar_.y) / 2 };
  return frameRect;
}
void gladyshev::Parallelogram::move(double dx, double dy)
{
  p1FramePar_.x += dx;
  p2FramePar_.x += dx;
  p1FramePar_.y += dy;
  p2FramePar_.y += dy;
}
void gladyshev::Parallelogram::move(const point_t& newPos)
{
  move(newPos.x - getFrameRect().pos.x, newPos.y - getFrameRect().pos.y);
}
void gladyshev::Parallelogram::scale(const point_t& p4, double factor)
{
  if (factor <= 0)
  {
    throw std::logic_error("bad factor");
  }
  double posfinishx = getFrameRect().pos.x;
  double posfinishy = getFrameRect().pos.x;
  move(p4);
  rectangle_t frameRect = getFrameRect();
  p1FramePar_.x = p1FramePar_.x - (frameRect.pos.x - p1FramePar_.x) * (factor - 1);
  p1FramePar_.y = p1FramePar_.y - (frameRect.pos.y - p1FramePar_.y) * (factor - 1);
  p2FramePar_.x = p2FramePar_.x - (frameRect.pos.x - p2FramePar_.x) * (factor - 1);
  p2FramePar_.y = p2FramePar_.y - (frameRect.pos.y - p2FramePar_.y) * (factor - 1);
  move(-(p4.x - posfinishx) * factor, -(p4.y - posfinishy) * factor);
  kf_ = factor * factor;
}