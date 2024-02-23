#include "composite_shape.hpp"
#include <limits>
#include <utility>
#include <stdexcept>
#include <algorithm>
#include "base-types.hpp"
#include "scale_figures.hpp"

nikitov::CompositeShape::CompositeShape():
  sizeOfArray_(0),
  figures_(nullptr)
{}

nikitov::CompositeShape::CompositeShape(const CompositeShape& other):
  sizeOfArray_(other.sizeOfArray_),
  figures_(new Shape*[sizeOfArray_])
{
  size_t i = 0;
  try
  {
    for (i = 0; i != sizeOfArray_; ++i)
    {
      figures_[i] = other[i].clone();
    }
  }
  catch (const std::bad_alloc&)
  {
    deleteArray(figures_, i);
    delete[] figures_;
    throw;
  }
}

nikitov::CompositeShape::CompositeShape(CompositeShape&& other):
  sizeOfArray_(other.sizeOfArray_),
  figures_(other.figures_)
{
  other.sizeOfArray_ = 0;
  other.figures_ = nullptr;
}

nikitov::CompositeShape::~CompositeShape()
{
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    delete figures_[i];
  }
  delete[] figures_;
}

nikitov::CompositeShape& nikitov::CompositeShape::operator=(const CompositeShape& other)
{
  CompositeShape temp(other);
  if (std::addressof(other) != this)
  {
    swap(temp);
  }
  return *this;
}

nikitov::CompositeShape& nikitov::CompositeShape::operator=(CompositeShape&& other)
{
  CompositeShape temp(std::move(other));
  if (std::addressof(other) != this)
  {
    swap(temp);
    other.sizeOfArray_ = 0;
    other.figures_ = nullptr;
  }
  return *this;
}

nikitov::Shape& nikitov::CompositeShape::operator[](size_t index)
{
  return *(figures_[index]);
}

const nikitov::Shape& nikitov::CompositeShape::operator[](size_t index) const
{
  return *(figures_[index]);
}

void nikitov::CompositeShape::push_back(Shape* figure)
{
  increaseArray();
  figures_[sizeOfArray_ - 1] = figure;
}

void nikitov::CompositeShape::pop_back()
{
  if (empty())
  {
    throw std::logic_error("Error: Nothing to delete");
  }
  decreaseArray();
}

nikitov::Shape& nikitov::CompositeShape::at(size_t index)
{
  if (index >= sizeOfArray_)
  {
    throw std::out_of_range("Error: Index out of range");
  }
  return *figures_[index];
}

const nikitov::Shape& nikitov::CompositeShape::at(size_t index) const
{
  if (index >= sizeOfArray_)
  {
    throw std::out_of_range("Error: Index out of range");
  }
  return *figures_[index];
}

size_t nikitov::CompositeShape::size() const
{
  return sizeOfArray_;
}

bool nikitov::CompositeShape::empty() const
{
  return !sizeOfArray_;
}

double nikitov::CompositeShape::getArea() const
{
  double sumOfAreas = 0.0;
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    sumOfAreas += figures_[i]->getArea();
  }
  return sumOfAreas;
}

nikitov::rectangle_t nikitov::CompositeShape::getFrameRect() const
{
  if (empty())
  {
    throw std::logic_error("Error: Empty array");
  }
  double maxX = std::numeric_limits< double >::lowest();
  double maxY = maxX;
  double minX = std::numeric_limits< double >::max();
  double minY = minX;
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    rectangle_t frame = figures_[i]->getFrameRect();
    maxX = std::max(maxX, frame.pos.x + (frame.width / 2.0));
    maxY = std::max(maxY, frame.pos.y + (frame.height / 2.0));
    minX = std::min(minX, frame.pos.x - (frame.width / 2.0));
    minY = std::min(minY, frame.pos.y - (frame.height / 2.0));
  }
  point_t center = { minX + (maxX - minX) / 2.0, minY + (maxY - minY) / 2.0 };
  return { maxX - minX, maxY - minY, center };
}

void nikitov::CompositeShape::move(const point_t& point)
{
  point_t center = getFrameRect().pos;
  move(point.x - center.x, point.y - center.y);
}

void nikitov::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    figures_[i]->move(dx, dy);
  }
}

void nikitov::CompositeShape::scale(double ratio)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    scaleFigure(figures_[i], center, ratio);
  }
}

void nikitov::CompositeShape::increaseArray()
{
  Shape** temp = new Shape*[sizeOfArray_ + 1];
  for (size_t i = 0; i != sizeOfArray_; ++i)
  {
    temp[i] = figures_[i];
  }
  delete[] figures_;
  ++sizeOfArray_;
  figures_ = temp;
}

void nikitov::CompositeShape::decreaseArray()
{
  Shape** temp = new Shape*[sizeOfArray_ - 1];
  delete figures_[sizeOfArray_];
  for (size_t i = 0; i != sizeOfArray_ - 1; ++i)
  {
    temp[i] = figures_[i];
  }
  delete[] figures_;
  --sizeOfArray_;
  figures_ = temp;
}

void nikitov::CompositeShape::swap(CompositeShape& other)
{
  std::swap(sizeOfArray_, other.sizeOfArray_);
  std::swap(figures_, other.figures_);
}

void nikitov::deleteArray(nikitov::Shape** figures, size_t numberOfFigures)
{
  for (size_t i = 0; i != numberOfFigures; ++i)
  {
    delete figures[i];
  }
}
