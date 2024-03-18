#ifndef COMPOSITE_HPP
#define COMPOSITE_HPP
#include <ostream>
#include "shape.hpp"

namespace shabalin
{
class CompositeShape
{
public:
    CompositeShape() = default;
    CompositeShape(const CompositeShape& obj);
    CompositeShape(CompositeShape&& obj);
    virtual ~CompositeShape();
    CompositeShape& operator=(const CompositeShape& obj);
    CompositeShape& operator=(CompositeShape&& obj);
    void scale(point_t p, double scale);
    double getArea() const;
    rectange_t getFrameRect() const;
    void push_back(Shape* shp);
    void pop_back();
    Shape* at(size_t id);
    const Shape* at(size_t id) const;
    Shape* operator[](size_t id);
    const Shape* operator[](size_t id) const;
    bool empty() const;
    size_t size() const;
private:
    Shape **shapes = nullptr;
    size_t count = 0;
    size_t capacity = 0;
};
std::ostream& operator<<(std::ostream& os, const CompositeShape& compositeShape);
}

#endif
