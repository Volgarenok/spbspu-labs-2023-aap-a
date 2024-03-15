#include "parallelogram.hpp"

#include <stdexcept>
#include "base-types.hpp"
#include "shape-creation.hpp"

arakelyan::Parallelogram::Parallelogram(point_t fp, point_t sp, point_t tp):
  p1_(fp),
  p2_(sp),
  p3_(tp)
{
  if (!((p1_.y == p2_.y) || (p1_.y == p3_.y) || (p2_.y == p3_.y)))
  {
    throw std::logic_error("The provided points do not form a parallelogram!");
  }
  if ((p1_.x == 0) && (p1_.y == 0) && (p2_.x == 0) && (p2_.y == 0) && (p3_.x == 0) && (p3_.y == 0))
  {
    throw std::logic_error("Invalid points for parallelogram!");
  }
}

double arakelyan::Parallelogram::getArea() const
{
  rectangle_t dataFrameOfPar = getFrameRect();
  if (p1_.y == p2_.y)
  {
    return std::abs((p1_.x - p2_.x) * dataFrameOfPar.height);
  }
  else
  {
    return std::abs((p2_.x - p3_.x) * dataFrameOfPar.height);
  }
}

arakelyan::rectangle_t arakelyan::Parallelogram::getFrameRect() const
{
  double width = std::abs(p2_.x - p1_.x) + std::abs(p2_.x - p3_.x);
  double height = 0;
  if (p2_.y == p1_.y)
  {
    height = std::abs(p3_.y - p2_.y);
  }
  else
  {
    height = std::abs(p2_.y - p1_.y);
  }

  point_t midPointOfRect = {0, 0};
  if (p1_.x <= p2_.x && p1_.x <= p3_.x)
  {
    midPointOfRect.x = p1_.x + (width / 2.0);
  }
  else if (p2_.x <= p1_.x && p2_.x <= p3_.x)
  {
    midPointOfRect.x = p2_.x + (width / 2.0);
  }
  else
  {
    midPointOfRect.x = p3_.x + (width / 2.0);
  }

  if (p1_.y > p2_.y || p1_.y > p3_.y)
  {
    midPointOfRect.y = p1_.y - (height / 2.0);
  }
  else
  {
    midPointOfRect.y = p1_.y + (height / 2.0);
  }

  return {width, height, midPointOfRect};
}

void arakelyan::Parallelogram::move(const point_t point)
{
  rectangle_t rectOfParal = getFrameRect();
  double delX = point.x - rectOfParal.pos.x;
  double delY = point.y - rectOfParal.pos.y;
  move(delX, delY);
}

void arakelyan::Parallelogram::move(const double delX, const double delY)
{
  point_t * pointsArray[3] = {&p1_, &p2_, &p3_};
  for (size_t i = 0; i < 3; i++)
  {
    pointsArray[i]->x += delX;
    pointsArray[i]->y += delY;
  }
}

void arakelyan::Parallelogram::scaleShape(const double k)
{
  rectangle_t rectOfParal = getFrameRect();
  scaleForParAndDiam(rectOfParal, p1_, p2_, p3_, k);
}
