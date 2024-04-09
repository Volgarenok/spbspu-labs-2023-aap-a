#ifndef TRIANGLE_H
#define TRIANGLE_H
#include <istream>
#include "shape.h"

Shape* inputTriangle(std::istream& input);

class Triangle: public Shape
{
public:
  Triangle(point_t pos1, point_t pos2, point_t pos3);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t position);
  void move(double dx, double dy);
  void scale(double k) noexcept;
  Shape* clone() const override;
private:
  point_t points_[3];
  point_t findCenterOfTriangle() const;
};

#endif
