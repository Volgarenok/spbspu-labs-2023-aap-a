#ifndef COMPOSITESHAPE_HPP
#define COMPOSITESHAPE_HPP
#include "shape.hpp"
#include <cstddef>

namespace spiridonov
{
  class CompositeShape : public Shape
  {
  public:
    CompositeShape();
    ~CompositeShape();

    void addShape(Shape* shape);
    void removeShape(size_t index);
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    void move(point_t pos) override;
    void move(double x, double y) override;
    void scale(double coefficient, const point_t& scaleCenter) override;
    Shape* getShape(size_t index) const;
    void clear();


    size_t getShapesCount() const;

  private:
    Shape** shapePtrs;
    size_t shapes;
  };
}

#endif
