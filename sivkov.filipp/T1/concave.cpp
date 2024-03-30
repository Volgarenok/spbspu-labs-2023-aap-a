#include "concave.hpp"
#include <stdexcept>
#include <algorithm>
#include "othersFun.hpp"

sivkov::Concave::Concave(const point_t cvVer1, const point_t cvVer2, const point_t cvVer3, const point_t cvVer4):
  cvVer1_(cvVer1),
  cvVer2_(cvVer2),
  cvVer3_(cvVer3),
  cvVer4_(cvVer4)
{
  if (!checkIsTriangle(cvVer1_, cvVer2_, cvVer3_))
  {
    throw std::invalid_argument("The first three points do not form a triangle.");
  }
  if (!checkIsInsideTriangle(cvVer1_, cvVer2_, cvVer3_, cvVer4_))
  {
    throw std::invalid_argument("The fourth point is not inside the triangle formed by the first three points.");
  }
}

sivkov::Concave::~Concave() = default;

double sivkov::Concave::getArea() const
{
  double area = ((cvVer2_.x - cvVer1_.x) * (cvVer3_.y - cvVer1_.x)) - ((cvVer3_.x - cvVer1_.x) * (cvVer2_.y - cvVer1_.y));
  if (area < 0)
  {
    area = area * -0.5;
  }
  else
  {
    area = area * 0.5;
  }
  double secondArea = ((cvVer4_.x - cvVer1_.x) * (cvVer3_.y - cvVer1_.x)) - ((cvVer3_.x - cvVer1_.x) * (cvVer4_.y - cvVer1_.y));
  if (secondArea < 0)
  {
    secondArea = secondArea * -0.5;
  }
  else
  {
    secondArea = secondArea * 0.5;
  }
  if ((area - secondArea) < 0)
  {
    return (area - secondArea) * -1.0;
  }
  else
  {
    return (area - secondArea);
  }
};

sivkov::rectangle_t sivkov::Concave::getFrameRect() const
{
  double xmin = std::min({ cvVer1_.x, cvVer2_.x, cvVer3_.x, cvVer4_.x });
  double xmax = std::max({ cvVer1_.x, cvVer2_.x, cvVer3_.x, cvVer4_.x });
  double ymin = std::min({ cvVer1_.y, cvVer2_.y, cvVer3_.y, cvVer4_.y });
  double ymax = std::max({ cvVer1_.y, cvVer2_.y, cvVer3_.y, cvVer4_.y });

  return rectangle_t{point_t{xmin + (xmax - xmin) / 2, ymin + (ymax - ymin) / 2} ,(xmax - xmin), (ymax - ymin)};
}

void sivkov::Concave::move(const point_t newPos)
{
  point_t oldPos = cvVer4_;
  double dx = newPos.x - oldPos.x;
  double dy = newPos.y - oldPos.y;
  move(dx,dy);
}

void sivkov::Concave::move(const double x, const double y)
{
  point_t newXY = { x,y };
  cvVer1_ = shift(newXY, cvVer1_);
  cvVer2_ = shift(newXY, cvVer2_);
  cvVer3_ = shift(newXY, cvVer3_);

}

void sivkov::Concave::scale(const double k)
{
  if (k <= 0.0)
  {
    throw std::invalid_argument("k must be > 0\n");
  }
  point_t center = cvVer4_;
  cvVer1_ = doCenterShift(k, center, cvVer1_);
  cvVer2_ = doCenterShift(k, center, cvVer2_);
  cvVer3_ = doCenterShift(k, center, cvVer3_);
}

