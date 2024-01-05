#include "regular.hpp"
#include <cmath>
#include <stdexcept>

nikitov::Regular::Regular(point_t& firstPoint, point_t& secondPoint, point_t& thirdPoint):
  firstPoint_(firstPoint),
  secondPoint_(secondPoint),
  thirdPoint_(thirdPoint)
{
  double firstLine = pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2);
  double secondLine = pow(thirdPoint_.x - secondPoint_.x, 2) + pow(thirdPoint_.y - secondPoint_.y, 2);
  double thirdLine = pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2);
  if (!(firstLine + secondLine == thirdLine || secondLine + thirdLine == firstLine))
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
}

double nikitov::Regular::getArea()
{
  double firstLine = sqrt(pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2));
  double secondLine = sqrt(pow(thirdPoint_.x - secondPoint_.x, 2) + pow(thirdPoint_.y - secondPoint_.y, 2));
  double thirdLine = sqrt(pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = 0;
  if (abs(180 / (acos(firstLine/circumRadius))) - abs(int(180 / (acos(firstLine/circumRadius))) < 0.000001))
  {
    n = round(180 / (acos(firstLine/circumRadius)));
  }
  else
  {
    n = round(180 / (acos(secondLine/circumRadius)));
  }

  double a = 2 * circumRadius * sin(M_PI / n);
  return 0.5 * n * a * inRadius;
}

nikitov::rectangle_t nikitov::Regular::getFrameRect()
{
  double firstLine = sqrt(pow(firstPoint_.x - secondPoint_.x, 2) + pow(firstPoint_.y - secondPoint_.y, 2));
  double secondLine = sqrt(pow(thirdPoint_.x - secondPoint_.x, 2) + pow(thirdPoint_.y - secondPoint_.y, 2));
  double thirdLine = sqrt(pow(firstPoint_.x - thirdPoint_.x, 2) + pow(firstPoint_.y - thirdPoint_.y, 2));

  double circumRadius = std::max(firstLine, thirdLine);
  double inRadius = std::min(firstLine, thirdLine);
  int n = 0;
  if (abs(180 / (acos(firstLine/circumRadius))) - abs(int(180 / (acos(firstLine/circumRadius))) < 0.000001))
  {
    n = round(180 / (acos(firstLine/circumRadius)));
  }
  else
  {
    n = round(180 / (acos(secondLine/circumRadius)));
  }

  double height = 0;
  double width = 0;
  if (n % 2 == 0)
  {
    height = inRadius * 2;
    width = 2 * circumRadius * sin(n * M_PI / 2 / n);
  }
  else
  {
    height = inRadius + circumRadius;
    width = 2 * circumRadius * sin(n * M_PI / (2 * n + 1));
  }

  return {width, height, firstPoint_};
}

void nikitov::Regular::move(const point_t& point)
{
  double dx = point.x - firstPoint_.x;
  double dy = point.y - firstPoint_.y;
  move(dx, dy);
}

void nikitov::Regular::move(double dx, double dy)
{
  firstPoint_.x += dx;
  firstPoint_.y += dy;
  secondPoint_.x += dx;
  secondPoint_.y += dy;
  thirdPoint_.x += dx;
  thirdPoint_.y += dy;
}

void nikitov::Regular::scale(double ratio)
{
  secondPoint_.x = firstPoint_.x + (secondPoint_.x - firstPoint_.x) * ratio * ratio;
  secondPoint_.y = firstPoint_.y + (secondPoint_.y - firstPoint_.y) * ratio * ratio;
  thirdPoint_.x = firstPoint_.x + (thirdPoint_.x - firstPoint_.x) * ratio * ratio;
  thirdPoint_.y = firstPoint_.y + (thirdPoint_.y - firstPoint_.y) * ratio * ratio;
}
