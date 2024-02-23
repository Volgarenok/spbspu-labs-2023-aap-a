#include "compositeshape.hpp"
#include <cmath>
#include "inputshape.hpp"
#include "isoscale.hpp"

piyavkin::CompositeShape::CompositeShape():
  CompositeShape(0)
{}
piyavkin::CompositeShape::CompositeShape(size_t capacity):
  shapes_(new Shape* [capacity] {}),
  size_(0),
  capacity_(capacity)
{}
piyavkin::CompositeShape::~CompositeShape()
{
  clearMemory(shapes_, size_);
}
piyavkin::CompositeShape::CompositeShape(CompositeShape&& cs)
{
  swap(cs);
}
piyavkin::CompositeShape::CompositeShape(const CompositeShape& cs):
  shapes_(new Shape* [cs.capacity_] {}),
  size_(cs.size_),
  capacity_(cs.capacity_)
{
  for (size_t i = 0; i < size_; ++i)
  {
    try
    {
      shapes_[i] = cs.shapes_[i]->clone();
    }
    catch (const std::bad_alloc& e)
    {
      clearMemory(shapes_, i);
      throw;
    }
  }
}
piyavkin::CompositeShape& piyavkin::CompositeShape::operator=(const CompositeShape& cs)
{
  if (this != std::addressof(cs))
  {
    CompositeShape tempShape(cs);
    swap(tempShape);
  }
  return *this;
}
piyavkin::CompositeShape& piyavkin::CompositeShape::operator=(CompositeShape&& cs)
{
  if (std::addressof(cs) != this)
  {
    clearMemory(shapes_, size_);
    size_ = 0;
    capacity_ = 0;
    swap(cs);
  }
  return *this;
}
void piyavkin::CompositeShape::swap(CompositeShape& cs)
{
  std::swap(shapes_, cs.shapes_);
  std::swap(size_, cs.size_);
  std::swap(capacity_, cs.capacity_);
}
double piyavkin::CompositeShape::getArea() const
{
  double sum = 0;
  for (size_t i = 0; i < size_; ++i)
  {
    sum += shapes_[i]->getArea();
  }
  return sum;
}
size_t piyavkin::CompositeShape::size() const
{
  return size_;
}
bool piyavkin::CompositeShape::empty() const
{
  return size_ == 0;
}
piyavkin::rectangle_t piyavkin::CompositeShape::getFrameRect() const
{
  double minX = shapes_[0]->getFrameRect().pos.x - shapes_[0]->getFrameRect().width / 2;
  double minY = shapes_[0]->getFrameRect().pos.y - shapes_[0]->getFrameRect().height / 2;
  double maxX = shapes_[0]->getFrameRect().pos.x + shapes_[0]->getFrameRect().width / 2;
  double maxY = shapes_[0]->getFrameRect().pos.y + shapes_[0]->getFrameRect().height / 2;
  for (size_t i = 1; i < size_; ++i)
  {
    minX = std::min(minX, shapes_[i]->getFrameRect().pos.x - shapes_[i]->getFrameRect().width / 2);
    maxX = std::max(maxX, shapes_[i]->getFrameRect().pos.x + shapes_[i]->getFrameRect().width / 2);
    minY = std::min(minY, shapes_[i]->getFrameRect().pos.y - shapes_[i]->getFrameRect().height / 2);
    maxY = std::max(maxY, shapes_[i]->getFrameRect().pos.y + shapes_[i]->getFrameRect().height / 2);
  }
  return {maxX - minX, maxY - minY, {(maxX + minX) / 2, (maxY + minY) / 2}};
}
void piyavkin::CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shapes_[i]->move(dx, dy);
  }
}
void piyavkin::CompositeShape::move(const point_t& bias)
{
  point_t pos = getFrameRect().pos;
  move(bias.x - pos.x, bias.y - pos.y);
}
void piyavkin::CompositeShape::scale(double k)
{
  if (k < 0)
  {
    throw std::logic_error("Сoefficient less than 0");
  }
  point_t posComposite = getFrameRect().pos;
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shapes_[i], posComposite, k);
  }
}
void piyavkin::CompositeShape::push_back(Shape* shape)
{
  if (capacity_ == size_)
  {
    Shape** oldShapes = nullptr;
    try
    {
      oldShapes = shapes_;
      shapes_ = new Shape* [capacity_ + 10] {};
      capacity_ += 10;
      if (oldShapes)
      {
        for (size_t i = 0; i < size_; ++i)
        {
          shapes_[i] = oldShapes[i];
        }
        delete[] oldShapes;
      }
    }
    catch (const std::bad_alloc& e)
    {
      shapes_ = oldShapes;
      throw;
    }
  }
  shapes_[size_++] = shape;
}
void piyavkin::CompositeShape::pop_back()
{
  if (empty())
  {
    throw std::logic_error("Out of array");
  }
  delete shapes_[size_--];
}
piyavkin::Shape& piyavkin::CompositeShape::at(size_t i)
{
  return const_cast< Shape& >(static_cast< const CompositeShape& >(*this).at(i));
}
const piyavkin::Shape& piyavkin::CompositeShape::at(size_t i) const
{
  if (i >= size_)
  {
    throw std::logic_error("Segmential fault");
  }
  return *shapes_[i];
}
piyavkin::Shape& piyavkin::CompositeShape::operator[](size_t i)
{
  return *shapes_[i];
}
const piyavkin::Shape& piyavkin::CompositeShape::operator[](size_t i) const
{
  return *shapes_[i];
}
