#include "rectangle.hpp"
#include "base-types.hpp"
#include <stdexcept>

namespace spiridonov
{
Rectangle::Rectangle(const point_t & p1, const point_t & p2):
bottomLeft_(p1),
topRight_(p2)
{}

double Rectangle::getArea() const
{
    return (topRight_.x - bottomLeft_.x) * (topRight_.y - bottomLeft_.y);
}

rectangle_t Rectangle::getFrameRect() const
{
    double width = topRight_.x - bottomLeft_.x;
    double height = topRight_.y - bottomLeft_.y;
    point_t pos = {(topRight_.x + bottomLeft_.x) / 2, (topRight_.y + bottomLeft_.y) / 2};
    return {width, height, pos};
}

void Rectangle::move(point_t pos)
{
    double width = topRight_.x - bottomLeft_.x;
    double height = topRight_.y - bottomLeft_.y;
    topRight_ = {pos.x + (width / 2), pos.y + (height / 2)};
    bottomLeft_ = {pos.x - (width / 2), pos.y - (height / 2)};
}

void Rectangle::move(double x, double y)
{
    topRight_.x += x;
    bottomLeft_.x += x;
    topRight_.y += y;
    bottomLeft_.y += y;
}

void Rectangle::scale(double coefficient)
{
    if(coefficient <= 0.0)
    {
        throw std::invalid_argument("Invalid coefficient");
    }
    else
    {
        double width = (topRight_.x - bottomLeft_.x) / 2;
        double height = (topRight_.y - bottomLeft_.y)  / 2;
        topRight_.x += (coefficient - 1.0) * width;
        topRight_.y += (coefficient - 1.0) * height;
        bottomLeft_.x -= (coefficient - 1.0) * width;
        bottomLeft_.y -= (coefficient - 1.0) * height;
    }
}
}
