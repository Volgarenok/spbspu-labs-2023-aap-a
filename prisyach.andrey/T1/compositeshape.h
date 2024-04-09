#ifndef COMPOSITESHAPE_H
#define COMPOSITESHAPE_H
#include <cstddef>
#include "shape.h"

class CompositeShape
{
public:
  CompositeShape();
  CompositeShape(Shape** shp, size_t size, size_t capacity);
  CompositeShape(const CompositeShape& rhs);
  CompositeShape(CompositeShape&& rhs);
  CompositeShape(size_t capacity);
  ~CompositeShape();
  void deleteshape_(Shape** shape, size_t size);
  CompositeShape & operator=(const CompositeShape& rhs);
  CompositeShape & operator=(CompositeShape&& rhs);
  Shape* operator[](size_t i);
  const Shape* operator[](size_t i) const;
  double getArea() const;
  rectangle_t getFrameRect() const;
  void move(double dx, double dy);
  void move(point_t position);
  void checkScale(double k);
  void scale(double k);
  Shape* at(size_t id);
  const Shape* at(size_t id) const;
  void changeShape(Shape** shape, Shape** newshape);
  void push_back(const Shape* shp);
  void push_back(Shape* shp);
  void pop_back();
  bool empty() const;
  size_t size() const;
  void checkIsoScale_(point_t point, double k);
  void isoScale_(point_t position, double k);
  CompositeShape* clone() const;
private:
  size_t size_;
  size_t capacity_;
  Shape** shape_;
};
#endif
