#include "compositeShape.hpp"
#include <algorithm>
#include <stdexcept>

namespace spiridonov
{
  CompositeShape::CompositeShape() :
    shapes(0),
    capacity(0),
    shapeptrs(nullptr)
  {}

  CompositeShape::CompositeShape(const CompositeShape& other) :
    shapes(other.shapes),
    capacity(other.capacity),
    shapeptrs(new Shape* [other.capacity])
  {
    std::copy(other.shapeptrs, other.shapeptrs + other.shapes, shapeptrs);
  }

  CompositeShape::CompositeShape(CompositeShape&& other) noexcept :
    shapes(other.shapes),
    capacity(other.capacity),
    shapeptrs(other.shapeptrs)
  {
    other.shapes = 0;
    other.capacity = 0;
    other.shapeptrs = nullptr;
  }

  CompositeShape::~CompositeShape()
  {
    delete[] shapeptrs;
    shapes = 0;
    capacity = 0;
  }

  CompositeShape& CompositeShape::operator=(const CompositeShape& other)
  {
    if (this != &other)
    {
      shapes = other.shapes;
      capacity = other.capacity;
      delete[] shapeptrs;
      shapeptrs = new Shape * [other.capacity];
      std::copy(other.shapeptrs, other.shapeptrs + other.shapes, shapeptrs);
    }
    return *this;
  }

  CompositeShape& CompositeShape::operator=(CompositeShape&& other) noexcept
  {
    if (this != &other)
    {
      shapes = other.shapes;
      capacity = other.capacity;
      delete[] shapeptrs;
      shapeptrs = other.shapeptrs;
      other.shapes = 0;
      other.capacity = 0;
      other.shapeptrs = nullptr;
    }
    return *this;
  }

  void CompositeShape::addShape(const Shape& shape)
  {

  }

  void CompositeShape::removeShape(size_t index)
  {

  }

  double CompositeShape::getArea() const
  {

  }

  rectangle_t CompositeShape::getFrameRect() const
  {

  }

  void CompositeShape::move(point_t pos)
  {

  }

  void CompositeShape::move(double x, double y)
  {

  }

  void CompositeShape::scale(double coefficient)
  {

  }
}
