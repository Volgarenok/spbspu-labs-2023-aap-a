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
    if (shapes == capacity)
    {
      size_t newCapacity = capacity == 0 ? 1 : capacity * 2;
      Shape** newShapePtrs = new Shape * [newCapacity];
      std::copy(shapeptrs, shapeptrs + shapes, newShapePtrs);
      delete[] shapeptrs;
      shapeptrs = newShapePtrs;
      capacity = newCapacity;
    }
    shapeptrs[shapes++] = new Shape(shape);
  }

  void CompositeShape::removeShape(size_t index)
  {
    if (index >= shapes)
    {
      throw std::out_of_range("Error: index out of range");
    }

    std::copy(shapeptrs + index + 1, shapeptrs + shapes, shapeptrs + index);
    --shapes;
  }

  double CompositeShape::getArea() const
  {
    double area = 0.0;
    for (size_t i = 0; i < shapes; ++i)
    {
      area += shapeptrs[i].getArea();
    }
    return area;
  }

  rectangle_t CompositeShape::getFrameRect() const
  {
    if (shapes == 0)
    {
      throw std::logic_error("Error: empty CompositeShape");
    }

    rectangle_t frameRect = shapeptrs[0]->getFrameRect();
    for (size_t i = 1; i < shapes; ++i)
    {
      rectangle_t currentFrameRect = shapeptrs[i]->getFrameRect();
      frameRect = getFrameRect(frameRect, currentFrameRect);
    }
    return frameRect;
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
