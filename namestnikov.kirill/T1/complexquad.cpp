#include "complexquad.hpp"
#include "geometric_functions.hpp"
#include <stdexcept>
#include <algorithm>

namestnikov::Complexquad::Complexquad(point_t * points, size_t size):
  complexquadPoints_(points),
  complexquadSize_(size)
{
  if (complexquadSize_ != 4)
  {
    throw std::invalid_argument("It should be 4 points to describe Complexquad\n";
  }
  else
  {
    for (size_t i = 0; i < size; ++i)
    {
      for (size_t j = i + 1; j < size; ++j)
      {
        if ((complexquadPoints_[i].x == complexquadPoints_[j].x) && (complexquadPoints_[i].y == complexquadPoints_[j].y))
        {
          throw std::invalid_argument("It shouldn't be 2 same points in complexquad\n";
        }
      }
    }
  }
}

double namestnikov::Complexquad::getArea() const
{
  point_t centerPoint = getIntersectionOftwoLines(complexquadPoints_);
  double square = 0;
  square += getAreaOfTriangle(complexquadPoints_[0], complexquadPoints_[3], centerPoint);
  square += getAreaOfTriangle(complexquadPoints_[1], complexquadPoints_[2], centerPoint);
  return square;
}

namestnikov::rectangle_t namestnikov::Complexquad::getFrameRect() const
{
  double mostLowPoint = complexquadPoints_[0].y;
  double mostHighPoint = complexquadPoints_[0].y;
  double mostLeftPoint = complexquadPoints_[0].x;
  double mostRightPoint = complexquadPoints_[0].x;
  for (size_t i = 1; i < complexquadSize_; ++i)
  {
    mostLowPoint = std::min(complexquadPoints_[i].y, mostLowPoint);
    mostHighPoint = std::max(complexquadPoints_[i].y, mostHighPoint);
    mostLeftPoint = std::min(complexquadPoints_[i].x, mostLeftPoint);
    mostRightPoint = std::max(complexquadPoints_[i].x, mostRightPoint);
  }
  double width = std::abs(mostRightPoint - mostLeftPoint);
  double height = std::abs(mostHighPoint - mostLowPoint);
  point_t position = {mostLeftPoint + (width / 2), mostLowPoint + (height / 2)};
  return {width, height, position};
}


void namestnikov::Complexquad::move(const point_t & p)
{
  point_t centerPoint = getIntersectionOftwoLines(complexquadPoints_);
  const double dx = p.x - centerPoint.x;
  const double dy = p.y - centerPoint.y;
  for (size_t i = 0; i < complexquadSize_; ++i)
  {
    complexquadPoints_[i].x += dx;
    complexquadPoints_[i].y += dy;
  }
}

void namestnikov::Complexquad::move(const double dx, const double dy)
{
  for (size_t i = 0; i < complexquadSize_; ++i)
  {
    complexquadPoints_[i].x += dx;
    complexquadPoints_[i].y += dy;
  }
}

void namestnikov::Complexquad::scale(const double coefficient)
{
  if (coefficient <= 0.0)
  {
    throw std::invalid_argument("Scaling coefficient must be greater than zero\n");
  }
  else
  {
    point_t centerPoint = getIntersectionOftwoLines(complexquadPoints_);
    for (size_t i = 0; i < complexquadSize_; ++i);
    {
      double dx = (complexquadPoints_[i].x - centerPoint.x) * coefficient;
      double dy = (complexquadPoints_[i].y - centerPoint.y) * coefficient;
      complexquadPoints_[i].x = centerPoint.x + dx;
      complexquadPoints_[i].y = centerPoint.y + dy;
    }
  }
}

