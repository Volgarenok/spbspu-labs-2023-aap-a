#include "diamond.hpp"
#include <stdexcept>
#include <cmath>
#include "geometryFunc.hpp"


void zakozhurnikova::initPoints(point_t* points, const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree)
{
  double sqrA = std::pow(getDistance(pointOne, pointTwo), 2.0);
  double sqrB = std::pow(getDistance(pointOne, pointThree), 2.0);
  double sqrC = std::pow(getDistance(pointTwo, pointThree), 2.0);
  if (sqrA == sqrB + sqrC)
  {
    points[0] = pointThree;
    points[1] = pointTwo;
    points[2] = pointOne;
    return;
  }
  else if (sqrB == sqrA + sqrC)
  {
    points[0] = pointTwo;
    points[1] = pointOne;
    points[2] = pointThree;
    return;
  }
  else if (sqrC == sqrA + sqrB)
  {
    points[0] = pointOne;
    points[1] = pointTwo;
    points[2] = pointThree;
    return;
  }
  else
  {
    throw std::invalid_argument("Invalid diamond parameters");
  }
}

bool zakozhurnikova::isOnAxis(const point_t& center, const point_t& pointOne, const point_t& pointTwo)
{
  const bool isParallelFirst = ((center.x - pointOne.x == 0.0) && (center.y - pointTwo.y == 0.0));
  const bool isParallelSecond = ((center.x - pointTwo.x == 0.0) && (center.y - pointOne.y == 0.0));
  return isParallelFirst || isParallelSecond;
}

zakozhurnikova::Diamond::Diamond(const point_t& pointOne, const point_t& pointTwo, const point_t& pointThree):
  pointOne_(pointOne),
  pointTwo_(pointTwo),
  center_(pointThree)
{
  point_t points[3];
  initPoints(points, pointOne, pointTwo, pointThree);
  center_ = points[0];
  pointOne_ = points[1];
  pointTwo_ = points[2];
  if (!isOnAxis(center_, pointOne_, pointTwo_))
  {
    throw std::invalid_argument("These points do not define a diamond");
  }
}


double zakozhurnikova::Diamond::getArea() const
{
  double d1 = 2 * getDistance(pointOne_, center_);
  double d2 = 2 * getDistance(pointTwo_, center_);
  return 0.5 * d1 * d2;
}

zakozhurnikova::rectangle_t zakozhurnikova::Diamond::getFrameRect() const
{
  double width = std::abs(pointOne_.x - center_.x) * 2;
  double height = std::abs(pointTwo_.y - center_.y) * 2;
  if (width == 0.0)
  {
    width = std::abs(pointTwo_.x - center_.x) * 2;
    height = std::abs(pointOne_.y - center_.y) * 2;
  }
  return rectangle_t{width, height, center_};
}

void zakozhurnikova::Diamond::move(double dx, double dy)
{
  point_t shift = {dx, dy};
  pointOne_ += shift;
  pointTwo_ += shift;
  center_ += shift;
}

void zakozhurnikova::Diamond::move(const point_t& p)
{
  double shiftX = p.x - center_.x;
  double shiftY = p.y - center_.y;
  move(shiftX,  shiftY);
}


void zakozhurnikova::Diamond::unsafeScale(double k)
{
  pointOne_ = center_ - (center_ - pointOne_) * k;
  pointTwo_ = center_ - (center_ - pointTwo_) * k;
}
