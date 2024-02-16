#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace spiridonov
{

  Parallelogram::Parallelogram(rectangle_t rect) :
    arrayOfPoints{ {rect.pos.x, rect.pos.y},
                   {rect.pos.x + rect.width, rect.pos.y},
                   {rect.pos.x + rect.width / 2, rect.pos.y + rect.height} }
  {}

  double Parallelogram::getArea() const
  {
    double side1 = sqrt(pow(arrayOfPoints[1].x - arrayOfPoints[0].x, 2) + pow(arrayOfPoints[1].y - arrayOfPoints[0].y, 2));
    double side2 = sqrt(pow(arrayOfPoints[2].x - arrayOfPoints[1].x, 2) + pow(arrayOfPoints[2].y - arrayOfPoints[1].y, 2));
    return 0.5 * side1 * side2;
  }

  rectangle_t Parallelogram::getFrameRect() const
  {
    double minX = std::min({ arrayOfPoints[0].x, arrayOfPoints[1].x, arrayOfPoints[2].x });
    double minY = std::min({ arrayOfPoints[0].y, arrayOfPoints[1].y, arrayOfPoints[2].y });
    double maxX = std::max({ arrayOfPoints[0].x, arrayOfPoints[1].x, arrayOfPoints[2].x });
    double maxY = std::max({ arrayOfPoints[0].y, arrayOfPoints[1].y, arrayOfPoints[2].y });

    double width = maxX - minX;
    double height = maxY - minY;

    point_t center{ (minX + maxX) / 2, (minY + maxY) / 2 };

    return { width, height, center };
  }

  void Parallelogram::move(point_t pos)
  {
    double dx = pos.x - arrayOfPoints[0].x;
    double dy = pos.y - arrayOfPoints[0].y;

    for (int i = 0; i < 3; ++i)
    {
      arrayOfPoints[i].x += dx;
      arrayOfPoints[i].y += dy;
    }
  }

  void Parallelogram::move(double x, double y)
  {
    point_t newPos{ arrayOfPoints[0].x + x, arrayOfPoints[0].y + y };
    move(newPos);
  }

  void Parallelogram::scale(double coefficient)
  {
    if (coefficient <= 0)
    {
      throw std::invalid_argument("Error: invalid coefficient to scale");
    }

    point_t center = getFrameRect().pos;

    move(center);

    for (int i = 0; i < 3; ++i)
    {
      arrayOfPoints[i].x *= coefficient;
      arrayOfPoints[i].y *= coefficient;
    }

    move(-center.x, -center.y);
  }

}