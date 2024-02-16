#include "concave.hpp"
#include <stdexcept>
#include <cmath>
#include <algorithm>

namespace spiridonov
{
  Concave::Concave(point_t p1, point_t p2, point_t p3, point_t p4) :
    arrayOfPoints{ p1, p2, p3, p4 }
  {}

  double Concave::getArea() const
  {
    double area = 0.5 * fabs(
      arrayOfPoints[0].x * (arrayOfPoints[1].y - arrayOfPoints[2].y) +
      arrayOfPoints[1].x * (arrayOfPoints[2].y - arrayOfPoints[0].y) +
      arrayOfPoints[2].x * (arrayOfPoints[0].y - arrayOfPoints[1].y) +
      arrayOfPoints[3].x * (arrayOfPoints[0].y - arrayOfPoints[2].y) +
      arrayOfPoints[3].x * (arrayOfPoints[1].y - arrayOfPoints[0].y) +
      arrayOfPoints[3].x * (arrayOfPoints[2].y - arrayOfPoints[1].y)
    );
    return area;
  }

  rectangle_t Concave::getFrameRect() const
  {
    double minX = std::min({ arrayOfPoints[0].x, arrayOfPoints[1].x, arrayOfPoints[2].x, arrayOfPoints[3].x });
    double minY = std::min({ arrayOfPoints[0].y, arrayOfPoints[1].y, arrayOfPoints[2].y, arrayOfPoints[3].y });
    double maxX = std::max({ arrayOfPoints[0].x, arrayOfPoints[1].x, arrayOfPoints[2].x, arrayOfPoints[3].x });
    double maxY = std::max({ arrayOfPoints[0].y, arrayOfPoints[1].y, arrayOfPoints[2].y, arrayOfPoints[3].y });

    double width = maxX - minX;
    double height = maxY - minY;

    point_t center{ (minX + maxX) / 2, (minY + maxY) / 2 };

    return { width, height, center };
  }

  void Concave::move(point_t pos)
  {
    double dx = pos.x - arrayOfPoints[0].x;
    double dy = pos.y - arrayOfPoints[0].y;

    for (int i = 0; i < 4; ++i)
    {
      arrayOfPoints[i].x += dx;
      arrayOfPoints[i].y += dy;
    }
  }

  void Concave::move(double x, double y)
  {
    point_t newPos{ arrayOfPoints[0].x + x, arrayOfPoints[0].y + y };
    move(newPos);
  }

  void Concave::scale(double coefficient)
  {
    if (coefficient <= 0)
    {
      throw std::invalid_argument("Error: invalid coefficient to scale");
    }

    point_t center = getFrameRect().pos;

    for (int i = 0; i < 4; ++i)
    {
      double dx = arrayOfPoints[i].x - center.x;
      double dy = arrayOfPoints[i].y - center.y;

      arrayOfPoints[i].x = center.x + dx * coefficient;
      arrayOfPoints[i].y = center.y + dy * coefficient;
    }
    updateFrameRect();
  }

  void Concave::updateFrameRect()
  {
    double minX = std::min({ arrayOfPoints[0].x, arrayOfPoints[1].x, arrayOfPoints[2].x, arrayOfPoints[3].x });
    double minY = std::min({ arrayOfPoints[0].y, arrayOfPoints[1].y, arrayOfPoints[2].y, arrayOfPoints[3].y });
    double maxX = std::max({ arrayOfPoints[0].x, arrayOfPoints[1].x, arrayOfPoints[2].x, arrayOfPoints[3].x });
    double maxY = std::max({ arrayOfPoints[0].y, arrayOfPoints[1].y, arrayOfPoints[2].y, arrayOfPoints[3].y });

    double width = maxX - minX;
    double height = maxY - minY;

    point_t center{ (minX + maxX) / 2, (minY + maxY) / 2 };

    frameRect_ = { width, height, center };
  }
}