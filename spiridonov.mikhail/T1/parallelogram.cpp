#include "parallelogram.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace spiridonov
{
  Parallelogram::Parallelogram(double x1, double x2, double x3, double y1, double y2, double y3):
    arrayOfPoints_{ {x1, y1}, {x2, y2}, {x3, y3} }
  {
  }
  
  Parallelogram::~Parallelogram()
  {
  }

  double Parallelogram::getArea() const
  {
    double side1 = std::sqrt(pow(arrayOfPoints_[1].x - arrayOfPoints_[0].x, 2) + pow(arrayOfPoints_[1].y - arrayOfPoints_[0].y, 2));
    double side2 = std::sqrt(pow(arrayOfPoints_[2].x - arrayOfPoints_[1].x, 2) + pow(arrayOfPoints_[2].y - arrayOfPoints_[1].y, 2));
    return 0.5 * side1 * side2;
  }

  rectangle_t Parallelogram::getFrameRect() const
  {
    double minX = std::min({ arrayOfPoints_[0].x, arrayOfPoints_[1].x, arrayOfPoints_[2].x });
    double minY = std::min({ arrayOfPoints_[0].y, arrayOfPoints_[1].y, arrayOfPoints_[2].y });
    double maxX = std::max({ arrayOfPoints_[0].x, arrayOfPoints_[1].x, arrayOfPoints_[2].x });
    double maxY = std::max({ arrayOfPoints_[0].y, arrayOfPoints_[1].y, arrayOfPoints_[2].y });

    double width = maxX - minX;
    double height = maxY - minY;

    point_t center{ (minX + maxX) / 2, (minY + maxY) / 2 };

    return { width, height, center };
  }

  void Parallelogram::move(point_t pos)
  {
    double dx = pos.x - arrayOfPoints_[0].x;
    double dy = pos.y - arrayOfPoints_[0].y;

    for (int i = 0; i < 3; ++i)
    {
      arrayOfPoints_[i].x += dx;
      arrayOfPoints_[i].y += dy;
    }
  }

  void Parallelogram::move(double x, double y)
  {
    point_t newPos{ arrayOfPoints_[0].x + x, arrayOfPoints_[0].y + y };
    move(newPos);
  }

  void Parallelogram::scale(double coefficient)
  {
    if (coefficient <= 0)
    {
      throw std::invalid_argument("Error: invalid coefficient to scale");
    }

    point_t center = getFrameRect().pos;

    for (int i = 0; i < 3; ++i)
    {
      double dx = arrayOfPoints_[i].x - center.x;
      double dy = arrayOfPoints_[i].y - center.y;

      arrayOfPoints_[i].x = center.x + dx * coefficient;
      arrayOfPoints_[i].y = center.y + dy * coefficient;
    }
  }

  Parallelogram* Parallelogram::clone() const
  {
    return new Parallelogram(*this);
  }
}
