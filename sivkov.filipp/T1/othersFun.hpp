#ifndef OTHERSFUN_HPP
#define OTHERSFUN_HPP
#include <iostream>
#include "shape.hpp"

namespace sivkov
{
  void outputFrameRectInfo(std::ostream& out, const Shape* const* shape);
  void findCoefficient(double& a, double& b, double& c, const point_t ver1, const point_t ver2);
  double findLine(const point_t a, const point_t b);
  bool checkIsTriangle(const point_t first, const point_t second, const point_t third);
  bool checkIsInsideTriangle(const point_t A, const point_t B, const point_t C, const point_t D);
  void doScale(Shape* shape, point_t center, double k);
  point_t calculateVector(const point_t p1, const point_t p2);
  bool checkAreSegmentsIntersecting(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4);
  point_t findCenter(const point_t ver1, const point_t ver2, const point_t ver3, const point_t ver4);
  point_t doCenterShift(double k, point_t center, point_t ver);
  point_t shift(point_t newXY, point_t ver);
  void readTops(std::istream& input, double tops[], size_t numberOfTops);
  void deleteMemory(Shape** shapes, size_t count);
}
#endif
