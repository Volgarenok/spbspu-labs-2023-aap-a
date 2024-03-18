#include "composite_shape.hpp"
#include <stdexcept>
#include "geom_func.hpp"

erohin::CompositeShape::CompositeShape():
  capacity_(4),
  size_(0),
  shape_(new Shape* [4]{ nullptr })
{}

erohin::CompositeShape::CompositeShape(const CompositeShape& rhs):
  capacity_(rhs.capacity_),
  size_(rhs.size_),
  shape_(new Shape* [rhs.capacity_]{ nullptr })
{
  for (size_t i = 0; i < size_; ++i)
  {
    try
    {
      shape_[i] = rhs.shape_[i]->clone();
    }
    catch (const std::bad_alloc&)
    {
      freeShape(shape_, i);
      throw;
    }
  }
}

erohin::CompositeShape::CompositeShape(CompositeShape&& rhs) noexcept:
  capacity_(rhs.capacity_),
  size_(rhs.size_),
  shape_(rhs.shape_)
{
  rhs.capacity_ = 0;
  rhs.size_ = 0;
  shape_ = nullptr;
}

erohin::CompositeShape::~CompositeShape()
{
  freeShape(shape_, size_);
}

erohin::CompositeShape& erohin::CompositeShape::operator=(const CompositeShape& rhs)
{
  if (this != std::addressof(rhs))
  {
    CompositeShape temp(rhs);
    swap(temp);
  }
  return *this;
}

erohin::CompositeShape& erohin::CompositeShape::operator=(CompositeShape&& rhs) noexcept
{
  if (this != std::addressof(rhs))
  {
    CompositeShape temp(std::move(rhs));
    swap(temp);
  }
  return *this;
}

erohin::Shape* erohin::CompositeShape::operator[](size_t index)
{
  return shape_[index];
}

const erohin::Shape* erohin::CompositeShape::operator[](size_t index) const
{
  return shape_[index];
}

erohin::Shape* erohin::CompositeShape::at(size_t index)
{
  if (index > size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return shape_[index];
}

const erohin::Shape* erohin::CompositeShape::at(size_t index) const
{
  if (index > size_)
  {
    throw std::out_of_range("Index is out of range");
  }
  return shape_[index];
}

void erohin::CompositeShape::push(const Shape* shape)
{
  if (size_ == capacity_)
  {
    resize(2 * capacity_);
  }
  shape_[size_++] = const_cast< Shape* >(shape);
}

void erohin::CompositeShape::pop()
{
  if (empty())
  {
    throw std::underflow_error("Composite shape is empty");
  }
  delete shape_[size_--];
}

bool erohin::CompositeShape::empty() const
{
  return (size_ == 0);
}

size_t erohin::CompositeShape::size() const
{
  return size_;
}

double erohin::CompositeShape::getArea() const
{
  double sumArea = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    sumArea += shape_[i]->getArea();
  }
  return sumArea;
}

erohin::rectangle_t erohin::CompositeShape::getFrameRect() const
{
  point_t point[2 * size_] = { 0.0, 0.0 };
  rectangle_t frameRect = { 0.0, 0.0, { 0.0, 0.0 } };
  for (size_t i = 0; i < size_; ++i)
  {
    frameRect = shape_[i]->getFrameRect();
    point[2 * i].x = frameRect.pos.x - frameRect.width / 2.0;
    point[2 * i].y = frameRect.pos.y - frameRect.height / 2.0;
    point[2 * i + 1].x = frameRect.pos.x + frameRect.width / 2.0;
    point[2 * i + 1].y = frameRect.pos.y + frameRect.height / 2.0;
  }
  return findPointsFrameRect(point, 2 * size_);
}

void erohin::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}

void erohin::CompositeShape::move(point_t point)
{
  rectangle_t frameRect = getFrameRect();
  double dx = point.x - frameRect.pos.x;
  double dy = point.y - frameRect.pos.y;
  move(dx, dy);
}

void erohin::CompositeShape::scale(double ratio)
{
  point_t center = getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], center, ratio);
  }
}

void erohin::CompositeShape::swap(CompositeShape& rhs)
{
  std::swap(capacity_, rhs.capacity_);
  std::swap(size_, rhs.size_);
  std::swap(shape_, rhs.shape_);
}

void erohin::CompositeShape::resize(size_t length)
{
  if (length < size_)
  {
    for (size_t i = length; i < size_; ++i)
    {
      delete shape_[i];
      shape_[i] = nullptr;
    }
    size_ = length;
  }
  else if (length > capacity_)
  {
    Shape** resized = new Shape* [length]{ nullptr };
    for (size_t i = 0; i < size_; ++i)
    {
      resized[i] = shape_[i];
    }
    delete[] shape_;
    capacity_ = length;
    shape_ = resized;
  }
}

void erohin::freeShape(Shape** shape, size_t size)
{
  for (size_t i = 0; i < size; ++i)
  {
    delete shape[i];
  }
  delete[] shape;
}
