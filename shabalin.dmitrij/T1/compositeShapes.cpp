#include "compositeShapes.hpp"

#include <algorithm>
#include <iomanip>
#include <stdexcept>

namespace shabalin
{

  CompositeShape::CompositeShape(const CompositeShape &obj)
  {
    count = obj.count;
    capacity = count;
    shapes = new Shape *[count];
    for (size_t i = 0; i < count; ++i)
    {
      shapes[i] = obj.shapes[i]->clone();
    }
  }
  CompositeShape::CompositeShape(CompositeShape &&obj)
  {
    count = obj.count;
    capacity = obj.capacity;
    shapes = obj.shapes;
    obj.shapes = nullptr;
    obj.count = obj.capacity = 0;
  }
  CompositeShape &CompositeShape::operator=(const CompositeShape &obj)
  {
    CompositeShape tmp(obj);
    std::swap(tmp, *this);
    return *this;
  }
  CompositeShape &CompositeShape::operator=(CompositeShape &&obj)
  {
    CompositeShape tmp(obj);
    std::swap(tmp, *this);
    return *this;
  }
  CompositeShape::~CompositeShape()
  {
    if (!this->empty())
    {
      for (size_t i = 0; i < count; ++i)
      {
        delete shapes[i];
      }
    }
    if (shapes)
    {
      delete[] shapes;
    }
  }
  void CompositeShape::scale(point_t p, double scale)
  {
    for (size_t i = 0; i < size(); ++i)
    {
      Shape *shape = shapes[i];
      point_t oldCenter = shape->getFrameRect().pos;
      shape->move(p);
      point_t newCenter = shape->getFrameRect().pos;
      shape->scale(scale);
      const double dx = (oldCenter.x - newCenter.x) * scale;
      const double dy = (oldCenter.y - newCenter.y) * scale;
      shape->move(dx, dy);
    }
  }
  double CompositeShape::getArea() const
  {
    double area = 0.0;
    for (size_t i = 0; i < size(); ++i)
    {
      area += shapes[i]->getArea();
    }
    return area;
  }
  rectangle_t CompositeShape::getFrameRect() const
  {
    point_t bl = shapes[0]->getFrameRect().bl();
    point_t ur = shapes[0]->getFrameRect().ur();
    for (size_t i = 1; i < count; ++i)
    {
      point_t other_bl = shapes[i]->getFrameRect().bl();
      point_t other_ur = shapes[i]->getFrameRect().ur();
      bl.x = std::min({bl.x, ur.x, other_bl.x, other_ur.x});
      bl.y = std::min({bl.y, ur.y, other_bl.y, other_ur.y});
      ur.x = std::max({bl.x, ur.x, other_bl.x, other_ur.x});
      ur.x = std::max({bl.y, ur.y, other_bl.y, other_ur.y});
    }
    double width = ur.x - bl.x;
    double height = ur.y - bl.y;
    point_t center{bl.x + width / 2.0, bl.y + height / 2.0};
    return {center, width, height};
  }
  void CompositeShape::push_back(Shape *shp)
  {
    if (count == capacity)
    {
      size_t newCapacity = (capacity == 0 ? 10 : capacity) * 1.5;
      Shape **newShapes = new Shape *[newCapacity];
      for (size_t i = 0; i < count; ++i)
      {
        newShapes[i] = shapes[i];
      }
      delete shapes;
      shapes = newShapes;
      capacity = newCapacity;
    }
    shapes[count++] = shp;
  }
  void CompositeShape::pop_back()
  {
    delete shapes[--count];
  }
  const Shape *CompositeShape::at(size_t id) const
  {
    if (id >= count)
    {
      throw std::out_of_range("Index is out of bounds");
    }
    return shapes[id];
  }
  Shape *CompositeShape::at(size_t id)
  {
    return const_cast<Shape *>(
        static_cast<const CompositeShape &>(*this).at(id));
  }
  const Shape *CompositeShape::operator[](size_t id) const
  {
    return shapes[id];
  }
  Shape *CompositeShape::operator[](size_t id)
  {
    return const_cast<Shape *>(
        static_cast<const CompositeShape &>(*this)[id]);
  }
  bool CompositeShape::empty() const
  {
    return count == 0;
  }
  size_t CompositeShape::size() const
  {
    return count;
  }
  std::ostream &operator<<(std::ostream &os, const CompositeShape &compositeShape)
  {
    os << std::fixed << std::setprecision(1) << compositeShape.getArea();
    for (size_t i = 0; i < compositeShape.size(); ++i)
    {
      rectangle_t frameRect = compositeShape[i]->getFrameRect();
      point_t bottom_left = frameRect.bl();
      point_t upper_right = frameRect.ur();
      os << std::fixed << std::setprecision(1) << " "
      << bottom_left.x << " " << bottom_left.y << " "
      << upper_right.x << " " << upper_right.y;
    }
    return os;
  }
}
