#include "compositeShape.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>
#include "rectangle.hpp"

spiridonov::CompositeShape::CompositeShape(): shapePtrs(nullptr), shapes(0), capacity_(0), scaleCoefficient(1.0)
{
}

spiridonov::CompositeShape::~CompositeShape()
{
  clear();
}

spiridonov::CompositeShape* spiridonov::CompositeShape::clone() const
{
  CompositeShape* newComposite = new CompositeShape();
  newComposite->capacity_ = this->capacity_;

  try
  {
    for (size_t i = 0; i < this->shapes; ++i)
    {
      auto clonedShape = this->shapePtrs[i]->clone();
      newComposite->addShape(clonedShape);
    }
  }
  catch(const std::exception& e)
  {
    for (size_t i = 0; i < newComposite->shapes; ++i)
    {
      delete newComposite->shapePtrs[i];
    }
    delete newComposite;
    throw;
  }
  return newComposite;
}


void spiridonov::CompositeShape::addShape(Shape* shape)
{
  if (shapes >= capacity_)
  {
    size_t newCapacity = (capacity_ == 0) ? 1 : 2 * capacity_;
    Shape** tempArray = new Shape * [newCapacity];
    for (size_t i = 0; i < shapes; ++i)
    {
      tempArray[i] = shapePtrs[i];
    }
    delete[] shapePtrs;
    shapePtrs = tempArray;
    capacity_ = newCapacity;
  }
  shapePtrs[shapes] = shape;
  ++shapes;
}

void spiridonov::CompositeShape::removeShape(size_t index)
{
  if (index >= shapes)
  {
    throw std::out_of_range("Error: index out of range");
  }

  delete shapePtrs[index];

  for (size_t i = index; i < shapes - 1; ++i)
  {
    shapePtrs[i] = shapePtrs[i + 1];
  }

  --shapes;
}

void spiridonov::CompositeShape::setScaleCoefficient(double coefficient)
{
  scaleCoefficient = coefficient;
}

double spiridonov::CompositeShape::getArea() const
{
  double totalArea = 0.0;
  double currentScaleCoefficient = scaleCoefficient;

  for (size_t i = 0; i < shapes; ++i)
  {
    totalArea += shapePtrs[i]->getArea();
  }

  totalArea = ceil(totalArea);

  totalArea *= currentScaleCoefficient * currentScaleCoefficient;

  return totalArea;
}

spiridonov::rectangle_t spiridonov::CompositeShape::getFrameRect() const
{
  if (shapes == 0)
  {
    throw std::logic_error("Error: CompositeShape is empty");
  }

  rectangle_t frameRect = shapePtrs[0]->getFrameRect();
  for (size_t i = 1; i < shapes; ++i)
  {
    rectangle_t currentFrameRect = shapePtrs[i]->getFrameRect();
    double left = std::min(frameRect.pos.x - frameRect.width / 2, currentFrameRect.pos.x - currentFrameRect.width / 2);
    double right = std::max(frameRect.pos.x + frameRect.width / 2, currentFrameRect.pos.x + currentFrameRect.width / 2);
    double top = std::max(frameRect.pos.y + frameRect.height / 2, currentFrameRect.pos.y + currentFrameRect.height / 2);
    double bottom = std::min(frameRect.pos.y - frameRect.height / 2, currentFrameRect.pos.y - currentFrameRect.height / 2);

    frameRect.width = right - left;
    frameRect.height = top - bottom;
    frameRect.pos.x = (left + right) / 2;
    frameRect.pos.y = (top + bottom) / 2;
  }

  return frameRect;
}

size_t spiridonov::CompositeShape::getShapesCount() const
{
  return shapes;
}

void spiridonov::CompositeShape::move(point_t pos)
{
  for (size_t i = 0; i < shapes; ++i)
  {
    shapePtrs[i]->move(pos);
  }
}

void spiridonov::CompositeShape::move(double x, double y)
{
  for (size_t i = 0; i < shapes; ++i)
  {
    shapePtrs[i]->move(x, y);
  }
}

void spiridonov::CompositeShape::scale(double coefficient)
{
  rectangle_t frameRect = getFrameRect();
  const point_t center = frameRect.pos;

  for (size_t i = 0; i < shapes; ++i)
  {
    const point_t shapeCenter = shapePtrs[i]->getFrameRect().pos;
    double deltaX = (shapeCenter.x - center.x) * coefficient;
    double deltaY = (shapeCenter.y - center.y) * coefficient;

    shapePtrs[i]->move({ deltaX, deltaY });
    shapePtrs[i]->scale(coefficient);
  }
}

spiridonov::Shape* spiridonov::CompositeShape::getShape(size_t index) const
{
  if (index >= shapes)
  {
    throw std::out_of_range("Error: index out of range");
  }

  return shapePtrs[index];
}

void spiridonov::CompositeShape::clear()
{
  for (size_t i = 0; i < shapes; ++i)
  {
    delete shapePtrs[i];
  }
  delete[] shapePtrs;
  shapePtrs = nullptr;
  shapes = 0;
  capacity_ = 0;
}
