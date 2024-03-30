#include "regular.hpp"
#include <stdexcept>
#include <cmath>
#include <limits>
#include "doScale.hpp"

vyzhanov::Regular::Regular(const point_t& p1, const point_t& p2, const point_t& p3) :
  triangles_(nullptr),
  size_(0)
{
  double firstLine = std::pow(p1.x - p2.x, 2) + std::pow(p1.y - p2.y, 2);
  double secondLine = std::pow(p1.x - p3.x, 2) + std::pow(p1.y - p3.y, 2);
  double foundation = std::pow(p2.x - p3.x, 2) + std::pow(p2.y - p3.y, 2);
  bool isReg = !(firstLine + foundation == secondLine);
  isReg = isReg && !(foundation + secondLine == firstLine);
  isReg = isReg || (std::max(std::sqrt(firstLine), std::sqrt(secondLine)) > std::sqrt(foundation) * 2);
  if (isReg)
  {
    throw std::invalid_argument("Error: invalid regular agrugments");
  }
  double PI = 3.14159265358979323846;
  double smallRad = std::min(firstLine, secondLine);
  double bigRad = std::max(firstLine, secondLine);
  size_t sideCount = std::round(-2.0 * PI / (std::asin(smallRad / bigRad) * 2.0 - PI));
  size_ = sideCount;
  double len = 2.0 * bigRad * std::sin(PI / sideCount);
  double angle = 2.0 * asin(len / 2.0 / bigRad);
  triangles_ = new Triangle[sideCount + 1];
  point_t firstPoint;
  point_t secondPoint;
  firstPoint.x = p2.x - p1.x;
  firstPoint.y = p2.y - p1.y;
  secondPoint.x = p3.x - p1.x;
  secondPoint.y = p3.y - p1.y;
  for (size_t i = 0; i != sideCount; ++i)
  {
    double firstX = firstPoint.x;
    double firstY = firstPoint.y;
    double secondX = secondPoint.x;
    double secondY = secondPoint.y;
    firstPoint.x = firstX * std::cos(angle) - firstY * std::sin(angle);
    firstPoint.y = firstY * std::cos(angle) + firstX * std::sin(angle);
    secondPoint.x = secondX * std::cos(angle) - secondY * std::sin(angle);
    secondPoint.y = secondY * std::cos(angle) + secondX * std::sin(angle);
    triangles_[i] = Triangle(p1, firstPoint, secondPoint);
  }
}

double vyzhanov::Regular::getArea() const
{
  size_t area = 0;
  for (size_t i = 0; i != size_; i++)
  {
     area += triangles_[i].getArea();
  }
  return area * 2;
}

vyzhanov::rectangle_t vyzhanov::Regular::getFrameRect() const
{
  double maxX = std::numeric_limits< double >::min();
  double maxY = maxX;
  double minX = std::numeric_limits< double >::max();
  double minY = minX;
  for (size_t i = 0; i != size_; i++)
  {
    Triangle triangle = triangles_[i];
    double width = triangle.getFrameRect().width;
    double height = triangle.getFrameRect().height;
    point_t center = triangle.getFrameRect().pos;
    maxX = std::max(center.x + (height / 2), maxX);
    maxY = std::max(center.y + (width / 2), maxY);
    minX = std::min(center.x - (height / 2), minX);
    minY = std::min(center.y - (width / 2), minY);
  }
  point_t centerPoint = { (maxX - minX) / 2, (maxY - minY) / 2 };
  return { maxX - minX, maxY - minY, centerPoint };
}

void vyzhanov::Regular::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  double dx = point.x - center.x;
  double dy = point.y - center.y;
  for (size_t i = 0; i != size_; i++)
  {
    triangles_[i].move(dx, dy);
  }
}

void vyzhanov::Regular::move(double dx, double dy)
{
  for (size_t i = 0; i != size_; i++)
  {
    triangles_[i].move(dx, dy);
  }
}

void vyzhanov::Regular::scale(double ratio)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i != size_; i++)
  {
    doScale(triangles_[i], center, ratio);
  }
}

vyzhanov::Regular::~Regular()
{
  delete[] triangles_;
}
