#include "othersFun.hpp"
#include <cmath>
#include <stdexcept>
#include <iostream>
#include "base-types.hpp"
#include "shape.hpp"

namespace sivkov
{
  void outputFrameRectInfo(std::ostream& out, const Shape* const* shape)
  {
    out << " " << (*shape)->getFrameRect().pos.x - (*shape)->getFrameRect().width / 2 << " ";
    out << (*shape)->getFrameRect().pos.y - (*shape)->getFrameRect().height / 2 << " ";
    out << (*shape)->getFrameRect().pos.x + (*shape)->getFrameRect().width / 2 << " ";
    out << (*shape)->getFrameRect().pos.y + (*shape)->getFrameRect().height / 2;
  }

  void findCoefficient(double& a, double& b, double& c, const point_t ver1, const point_t ver2)
  {
    if (ver1.x == ver2.x)
    {
      a = 1;
      b = 0;
      c = -ver2.x;
    }
    else if (ver1.y == ver2.y)
    {
      a = 0;
      b = 1;
      c = -ver2.y;
    }
    else
    {
      a = 1;
      b = (ver2.x - ver1.x) / (ver1.y - ver2.y);
      c = -ver1.x * a - ver1.y * b;
    }
  }

  double findLine(const point_t a, const point_t b)
  {
    return std::sqrt(std::abs(a.x - b.x) * std::abs(a.x - b.x) + std::abs(a.y - b.y) * std::abs(a.y - b.y));
  }

  bool checkIsTriangle(const point_t first, const point_t second, const point_t third)
  {
    return (((third.x - first.x) / (second.x - first.x)) != ((third.y - first.y) / (second.y - first.y)));
  }

  bool checkIsInsideTriangle(const point_t A, const point_t B, const point_t C, const point_t D)
  {
    double ab = (B.y - A.y) * D.x + (A.x - B.x) * D.y + (B.x * A.y - A.x * B.y);
    double bc = (B.y - C.y) * D.x + (C.x - B.x) * D.y + (B.x * C.y - C.x * B.y);
    double ac = (C.y - A.y) * D.x + (A.x - C.x) * D.y + (C.x * A.y - A.x * C.y);
    return (ab < 0 && bc > 0 && ac > 0);
  }

  void doScale(Shape* shape, point_t center, double k)
  {
    if (k < 0)
    {
      throw std::invalid_argument("K cannot be < 0");
    }
    point_t pos = shape->getFrameRect().pos;
    shape->move(center);
    point_t newPos = shape->getFrameRect().pos;
    shape->scale(k);
    shape->move(k * (pos.x - newPos.x), k * (pos.y - newPos.y));
  }

  point_t findCenter(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4)
  {
    double a1 = 0, b1 = 0, c1 = 0, a2 = 0, b2 = 0, c2 = 0;

    findCoefficient(a1, b1, c1, ver1, ver2);
    findCoefficient(a2, b2, c2, ver3, ver4);

    if (a1 / a2 == b1 / b2)
    {
      throw std::invalid_argument("no intersection");
    }
    else
    {
      double x = 0, y = 0;
      double dx = c2 * b1 - c1 * b2;
      double dy = c1 * a2 - a1 * c2;
      double d = a1 * b2 - b1 * a2;
      x = dx / d;
      y = dy / d;
      return { x, y };
    }
  }

  point_t calculateVector(const point_t p1, const point_t p2)
  {
    return { p2.x - p1.x, p2.y - p1.y };
  }

  bool checkAreSegmentsIntersecting(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4)
  {
    point_t line1 = calculateVector(ver1, ver2);
    point_t line2 = calculateVector(ver1, ver3);
    point_t line3 = calculateVector(ver1, ver4);

    bool check1 = ((line1.x * line2.y - line1.y * line2.x) * (line1.x * line3.y - line1.y * line3.x) < 0);

    if (!check1)
    {
      return false;
    }
    point_t line4 = calculateVector(ver3, ver4);
    point_t line5 = calculateVector(ver3, ver1);
    point_t line6 = calculateVector(ver3, ver2);
    bool check2 = ((line4.x * line5.y - line4.y * line5.x) * (line4.x * line6.y - line4.y * line6.x) < 0);
    return check1 && check2;
  }

  point_t doCenterShift(double k, point_t center, point_t ver)
  {
    double x = center.x + (ver.x - center.x) * k;
    double y = center.y + (ver.y - center.y) * k;
    return point_t{ x,y };
  }

  point_t shift(point_t newXY, point_t ver)
  {
    double newX = ver.x + newXY.x;
    double newY = ver.y + newXY.y;
    return point_t{ newX, newY };
  }

  void readTops(std::istream& input, double tops[], size_t numberOfTops)
  {
    for (size_t i = 0; i < numberOfTops; ++i)
    {
      input >> tops[i];
    }

    if (!input)
    {
      throw std::runtime_error("Invalid tops");
    }
  }

  void deleteMemory(Shape** shapes, size_t count)
  {
    for (size_t i = 0; i < count; ++i)
    {
      delete shapes[i];
    }
    delete[] shapes;
  }

}

