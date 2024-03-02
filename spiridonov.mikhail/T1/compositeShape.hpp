#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "shape.hpp"
#include <cstddef>

namespace spiridonov
{
  class CompositeShape
  {
  public:
    CompositeShape();
    ~CompositeShape();
    CompositeShape* clone() const;
    void addShape(Shape* shape);
    void removeShape(size_t index);
    double getArea() const;
    void setScaleCoefficient(double coefficient);
    rectangle_t getFrameRect() const;
    void move(point_t pos);
    void move(double x, double y);
    void scale(double coefficient);
    Shape* getShape(size_t index) const;
    void clear();

    size_t getShapesCount() const;

  private:
    Shape** shapePtrs;
    size_t shapes;
    size_t capacity_;
    double scaleCoefficient;
  };
}

#endif
