#include "compositeshape.h"
#include <stdexcept>
#include "isoscale.h"

CompositeShape::CompositeShape():
  size_(0),
  capacity_(10),
  shape_(new Shape* [capacity_])
{}

CompositeShape::CompositeShape(Shape** rhp, size_t size, size_t capacity):
  size_(size),
  capacity_(capacity),
  shape_(rhp)
{}


CompositeShape::CompositeShape(const CompositeShape& rhs):
  CompositeShape(rhs.capacity_)
{
  for (size_t i = 0; i < rhs.size_; ++i)
  {
    shape_[i] = rhs.shape_[i]->clone();
    size_++;
  }
}

CompositeShape::CompositeShape(CompositeShape&& rhs):
  size_(rhs.size_),
  capacity_(rhs.capacity_),
  shape_(rhs.shape_)
{
  rhs.shape_ = nullptr;
  rhs.size_ = 0;
}

bool CompositeShape::empty() const
{
  return size_ == 0;
}

size_t CompositeShape::size() const
{
  return size_;
}

CompositeShape::CompositeShape(size_t capacity):
  size_(0),
  capacity_(capacity),
  shape_(new Shape* [capacity_])
{}

void CompositeShape::deleteshape_(Shape** shape, size_t size)
{
  for (size_t i = 0; i < size; i++)
  {
    delete shape[i];
  }
  delete[] shape;
}

CompositeShape& CompositeShape::operator=(const CompositeShape& rhs)
{
  Shape** new_data = new Shape* [rhs.capacity_];
  size_t new_size = 0;
  try
  {
    for (size_t i = 0; i < rhs.size_; ++i)
    {
      new_data[i] = rhs.shape_[i]->clone();
      new_size++;
    }
  }
  catch (...)
  {
    deleteshape_(new_data, new_size);
    throw;
  }
  deleteshape_(shape_, size_);
  shape_ = new_data;
  size_ = new_size;
  capacity_ = rhs.capacity_;
  return *this;
}

CompositeShape& CompositeShape::operator=(CompositeShape&& rhs)
{
  deleteshape_(shape_, size_);
  shape_ = rhs.shape_;
  rhs.shape_ = nullptr;
  size_ = rhs.size_;
  rhs.size_ = 0;
  capacity_ = rhs.capacity_;
  return *this;
}

CompositeShape::~CompositeShape()
{
  deleteshape_(shape_, size_);
}

Shape* CompositeShape::operator[](size_t i)
{
  return shape_[i];
}

const Shape* CompositeShape::operator[](size_t i) const
{
  return shape_[i];
}

double CompositeShape::getArea() const
{
  double area = 0.0;
  for (size_t i = 0; i < size_; ++i)
  {
    area += shape_[i]->getArea();
  }
  return area;
}

rectangle_t CompositeShape::getFrameRect() const
{
  rectangle_t rectangle = shape_[0]->getFrameRect();
  double maxx = rectangle.pos.x + rectangle.width / 2;
  double maxy = rectangle.pos.y + rectangle.height / 2;
  double minx = rectangle.pos.x + rectangle.width / 2;
  double miny = rectangle.pos.y + rectangle.height / 2;
  for (size_t i = 1; i < size_; i++)
  {
    rectangle_t rectangle1 = shape_[i]->getFrameRect();
    double rightupx = rectangle1.pos.x + rectangle1.width / 2;
    double rightupy = rectangle1.pos.y + rectangle1.height / 2;
    double leftdownx = rectangle1.pos.x - rectangle1.width / 2;
    double leftdowny = rectangle1.pos.y - rectangle1.height / 2;
    maxx = std::max(maxx, rightupx);
    maxy = std::max(maxy, rightupy);
    minx = std::min(minx, leftdownx);
    miny = std::min(miny, leftdowny);
  }
  point_t center({(minx + maxx) / 2, (miny + maxy) / 2});
  rectangle_t framerect{center, maxx - minx, maxy - miny};
  return framerect;
}

void CompositeShape::move(const point_t position)
{
  rectangle_t framerect = CompositeShape::getFrameRect();
  double dx = position.x - framerect.pos.x;
  double dy = position.y - framerect.pos.y;
  move(dx, dy);
}

void CompositeShape::move(double dx, double dy)
{
  for (size_t i = 0; i < size_; ++i)
  {
    shape_[i]->move(dx, dy);
  }
}

void CompositeShape::checkScale(double k)
{
  if (k <= 0)
  {
    throw std::logic_error("error");
  }
  scale(k);
}

void CompositeShape::scale(double k)
{
  rectangle_t frame = CompositeShape::getFrameRect();
  for (size_t i = 0; i < size_; ++i)
  {
    isoScale(shape_[i], frame.pos, k);
  }
}

void CompositeShape::checkIsoScale_(point_t point, double k)
{
  if (k <= 0)
  {
    throw std::logic_error("error");
  }
  isoScale_(point, k);
}

void CompositeShape::isoScale_(point_t position, double k)
{
  point_t position1 = getFrameRect().pos;
  move(position);
  point_t position2 = getFrameRect().pos;
  scale(k);
  double dx = (position1.x - position2.x) * k;
  double dy = (position1.y - position2.y) * k;
  move(dx, dy);
}

Shape* CompositeShape::at(size_t id)
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shape_[id];
}

const Shape* CompositeShape::at(size_t id) const
{
  if (id >= size_)
  {
    throw std::out_of_range("Check number");
  }
  return shape_[id];
}

void CompositeShape::push_back(Shape* shp)
{
  if (capacity_ == size_)
  {
    Shape** new_shape = new Shape* [capacity_ + 10];
    capacity_ += 10;
    for (size_t i = 0; i < size_; ++i)
    {
      new_shape[i] = shape_[i];
    }
    delete[] shape_;
    shape_ = new_shape;
  }
  shape_[size_++] = shp;
}

void CompositeShape::push_back(const Shape* shp)
{
  Shape* cloned = shp->clone();
  try
  {
    push_back(cloned);
  }
  catch (...)
  {
    delete cloned;
    throw;
  }
}

void CompositeShape::pop_back()
{
  delete shape_[size_ - 1];
  size_--;
}

CompositeShape* CompositeShape::clone() const
{
  Shape** cloned = new Shape* [capacity_];
  for (size_t i = 0; i < size_; i++)
  {
    try
    {
      cloned[i] = shape_[i]->clone();
    }
    catch (...)
    {
      for (size_t i = 0; i < size_; i++)
      {
        delete shape_[i];
      }
    }
  }
  return new CompositeShape(cloned, size_, capacity_);
}

