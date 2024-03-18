#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include "shape.hpp"

namespace shabalin
{
class Rectangle: public Shape
{
public:
    Rectangle(point_t bottom_left, point_t upper_right);
    ~Rectangle() = default;
    void move(point_t p) override;
    void move(double shift_x, double shift_y) override;
    void scale(double scale) override;
    double getArea() const override;
    rectangle_t getFrameRect() const override;
    Shape* clone() const override;
private:
    Rectangle(point_t center, size_t width, size_t height);
    point_t center_;
    double width_, height_;
};
}
#endif
