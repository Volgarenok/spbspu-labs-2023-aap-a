#ifndef COMPLEXQUAD_H
#define COMPLEXQUAD_H
#include <istream>
#include "triangle.h"
#include "shape.h"

Shape* inputComplexquad(std::istream& input);

class Complexquad: public Shape // абстрактный класс
{
public:
  Complexquad(point_t pos1, point_t pos2, point_t pos3, point_t pos4);
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(point_t position);
  void move(double dx, double dy);
  void scale(double k) noexcept;
  Shape* clone() const override;
private:
  point_t center_;
  Triangle triangle1_;
  Triangle triangle2_;
};

#endif
