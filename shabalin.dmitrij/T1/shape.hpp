#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <ostream>

#include "base-types.hpp"

namespace shabalin
{
class Shape
{
public:
    virtual void move(point_t p) = 0;
    virtual void move(double shift_x, double shift_y) = 0;
    virtual void scale(double scale) = 0;
    virtual double getArea() const = 0;
    virtual rectangle_t getFrameRect() const = 0;
    virtual Shape* clone() const = 0;
    virtual ~Shape() = default;
};
std::ostream& operator<<(std::ostream& os, const Shape& obj);

}
#endif
