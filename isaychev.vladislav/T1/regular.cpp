#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include "geometryFunctions.hpp"

bool canBeReg(double a, double c)
{
  double a1 = 0.0, c1 = 0.0;
  a1 = std::min(a, c);
  c1 = std::max(a, c);
  double angle = std::acos(a1 / c1);
  double n = 3.1415926535 / angle;
  double roundedN = std::round(n);
  if (std::fabs(roundedN - n) < 0.0001)
  {
    return true;
  }
  return false;
}

bool isTriangle(double a, double b, double c)
{
  double a1 = std::sqrt(a);
  double b1 = std::sqrt(b);
  double c1 = std::sqrt(c);
  if (a1 + b1 > c1 && a1 + c1 > b1 && b1 + c1 > a1)
  {
    return true;
  }
  return false;
}

double getSideSquare(const isaychev::point_t & p1, const isaychev::point_t & p2)
{
  return std::pow((p1.x - p2.x), 2) + std::pow((p1.y - p2.y), 2);
}

isaychev::Regular::Regular(const point_t & p1, const point_t & p2, const point_t & p3):
  center_(p1),
  closePnt_(p2),
  distPnt_(p3)
{
  double side1 = getSideSquare(p1, p2);
  double side2 = getSideSquare(p1, p3);
  double bottom = getSideSquare(p2, p3);
  bool regCheck = canBeReg(side1, side2);
  bool triCheck = isTriangle(side1, side2, bottom);
  if (side2 == side1 + bottom && regCheck == 1 && triCheck == 1)
  {
    closePnt_.x = p2.x;
    closePnt_.y = p2.y;
    distPnt_.x = p3.x;
    distPnt_.y = p3.y;
  }
  else if (!(side1 == side2 + bottom) || regCheck == 0 || triCheck == 0)
  {
    throw std::logic_error("Incorrect regular parameters");
  }
}

double getCoordSquared(double coord1, double coord2)
{
  return std::pow((coord1 - coord2), 2);
}

double isaychev::Regular::getArea() const
{
  double inRad = 0.0, bottom = 0.0, radX = 0.0, radY = 0.0;
  radX = getCoordSquared(distPnt_.x, closePnt_.x);
  radY = getCoordSquared(distPnt_.y, closePnt_.y);
  bottom = std::sqrt(radX + radY);
  radX = getCoordSquared(center_.x, closePnt_.x);
  radY = getCoordSquared(center_.y, closePnt_.y);
  inRad = std::sqrt(radX + radY);
  int numOfSides = std::round(3.1415926535 / std::atan(bottom / inRad));
  return bottom * inRad * numOfSides;
}

isaychev::rectangle_t isaychev::Regular::getFrameRect() const
{
  double radX = 0.0, radY = 0.0;
  radX = getCoordSquared(center_.x, closePnt_.x);
  radY = getCoordSquared(center_.y, closePnt_.y);
  double leg = std::sqrt(radX + radY);
  radX = (distPnt_.x - center_.x);
  radY = (distPnt_.y - center_.y);
  double outRad = std::sqrt(radX * radX + radY * radY);
  double initXAngle = std::acos(radX / outRad);
  double steerAngle = 2 * std::acos(leg / outRad);
  size_t numOfSides = std::round(3.1415926535 / std::acos(leg / outRad));
  double minX = 0.0, minY = 0.0, maxX = 0.0, maxY = 0.0;
  minX = maxX = distPnt_.x;
  minY = maxY = distPnt_.y;
  for (size_t i = 1.0; i < numOfSides; i++)
  {
    double currX = center_.x + outRad * std::cos(initXAngle + i * steerAngle);
    double currY = center_.y + outRad * std::sin(initXAngle + i * steerAngle);
    minX = std::min(minX, currX);
    maxX = std::max(maxX, currX);
    minY = std::min(minY, currY);
    maxY = std::max(maxY, currY);
  }
  double width = maxX - minX;
  double height = maxY - minY;
  point_t pos = {minX + (width / 2), minY + (height / 2)};
  return {width, height, pos};
}

void isaychev::Regular::move(double dX, double dY)
{
  changeCoords(center_, dX, dY);
  changeCoords(closePnt_, dX, dY);
  changeCoords(distPnt_, dX, dY);
}

void isaychev::Regular::move(const point_t & newPos)
{
  double dX = newPos.x - center_.x;
  double dY = newPos.y - center_.y;
  changeCoords(closePnt_, dX, dY);
  changeCoords(distPnt_, dX, dY);
  center_ = {newPos.x, newPos.y};
}

void scaleRegPnt(isaychev::point_t & p1, const isaychev::point_t & p2, double coeff)
{
  p1.x = p2.x + (p1.x - p2.x) * coeff;
  p1.y = p2.y + (p1.y - p2.y) * coeff;
}

void isaychev::Regular::doScale(double coeff)
{
  scaleRegPnt(distPnt_, center_, coeff);
  scaleRegPnt(closePnt_, center_, coeff);
}
