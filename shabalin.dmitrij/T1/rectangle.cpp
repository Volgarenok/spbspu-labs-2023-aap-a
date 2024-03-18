#include "rectangle.hpp"

#include <stdexcept>

namespace shabalin
{

Rectangle::Rectangle(point_t center, size_t width, size_t height) : center_(center), width_(width), height_(height)
{
}

Rectangle::Rectangle(point_t bottom_left, point_t upper_right)
{
    if (bottom_left.x >= upper_right.x ||
        bottom_left.y >= upper_right.y) {
        throw std::invalid_argument("Can't create rectangle with next arguments");
    }
    width_ = upper_right.x - bottom_left.x;
    height_ = upper_right.y - bottom_left.y;
    center_.x = bottom_left.x + width_ / 2.0;
    center_.y = bottom_left.y + height_ / 2.0;
}

void Rectangle::move(point_t p)
{
    center_ = p;
}

void Rectangle::move(double shift_x, double shift_y)
{
    center_.x += shift_x;
    center_.y += shift_y;
}

void Rectangle::scale(double scale)
{
    width_ *= scale;
    height_ *= scale;
}

Shape* Rectangle::clone() const
{
    return new Rectangle(center_, width_, height_);
}

double Rectangle::getArea() const
{
    return width_ * height_;
}

rectangle_t Rectangle::getFrameRect() const
{
    return rectangle_t{center_, width_, height_};
}

}
