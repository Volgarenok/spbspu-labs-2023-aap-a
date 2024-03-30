#include "complexquad.hpp"
#include <stdexcept>
#include <algorithm>
#include "othersFun.hpp"
sivkov::Complexquad::Complexquad(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4):
  cqVer1_(ver1),
  cqVer2_(ver2),
  cqVer3_(ver3),
  cqVer4_(ver4)
{
  if (!checkAreSegmentsIntersecting(ver1, ver2, ver3, ver4))
  {
    throw std::invalid_argument("Sides of the complex quad intersect. Invalid configuration.");
  }
}

double sivkov::Complexquad::getArea() const
{
  point_t center = findCenter(cqVer1_, cqVer2_, cqVer3_, cqVer4_);

  double ab = findLine(cqVer1_, center);
  double ac = findLine(cqVer4_, center);
  double cb = findLine(cqVer1_, cqVer4_);
  double halfPer = (ab + ac + cb) / 2.0;
  double area1 = std::sqrt(halfPer * (halfPer - ab) * (halfPer - ac) * (halfPer - cb));

  double ab1 = findLine(cqVer2_, center);
  double ac1 = findLine(cqVer3_, center);
  double cb1 = findLine(cqVer2_, cqVer3_);
  double halfPer2 = (ab1 + ac1 + cb1) / 2.0;
  double area2 = std::sqrt(halfPer2 * (halfPer2 - ab1) * (halfPer2 - ac1) * (halfPer2 - cb1));

  return area1 + area2;
}

sivkov::rectangle_t sivkov::Complexquad::getFrameRect() const
{
  double xmin = std::min({ cqVer1_.x, cqVer2_.x, cqVer3_.x, cqVer4_.x });
  double xmax = std::max({ cqVer1_.x, cqVer2_.x, cqVer3_.x, cqVer4_.x });
  double ymin = std::min({ cqVer1_.y, cqVer2_.y, cqVer3_.y, cqVer4_.y });
  double ymax = std::max({ cqVer1_.y, cqVer2_.y, cqVer3_.y, cqVer4_.y });

  return rectangle_t{ point_t{xmin + (xmax - xmin) / 2, ymin + (ymax - ymin) / 2} ,(xmax - xmin), (ymax - ymin) };
}

void sivkov::Complexquad::move(const point_t newPos)
{
  point_t center = findCenter(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
  const double dx = newPos.x - center.x;
  const double dy = newPos.y - center.y;
  move(dx, dy);
}

void sivkov::Complexquad::move(const double dx, const double dy)
{
  point_t newXY = { dx, dy };
  cqVer1_ = shift(newXY, cqVer1_);
  cqVer2_ = shift(newXY, cqVer2_);
  cqVer3_ = shift(newXY, cqVer3_);
  cqVer4_ = shift(newXY, cqVer4_);
}

void sivkov::Complexquad::scale(const double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must be > 0\n");
  }
  point_t centerPoint = findCenter(cqVer1_, cqVer2_, cqVer3_, cqVer4_);
  cqVer1_ = doCenterShift(k, centerPoint, cqVer1_);
  cqVer2_ = doCenterShift(k, centerPoint, cqVer2_);
  cqVer3_ = doCenterShift(k, centerPoint, cqVer3_);
  cqVer4_ = doCenterShift(k, centerPoint, cqVer4_);
}
