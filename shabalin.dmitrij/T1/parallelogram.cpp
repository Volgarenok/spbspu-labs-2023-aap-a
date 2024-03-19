#include "parallelogram.hpp"
#include "base-types.hpp"

#include <cmath>
#include <stdexcept>
#include <algorithm>

namespace shabalin
{
    Parallelogram::Parallelogram(point_t p1, point_t p2, point_t p3) :
        p1_(p1),
        p2_(p2),
        p3_(p3)
    {
        double dx1 = p2.x - p1.x;
        double dy1 = p2.y - p1.y;
        double dx2 = p3.x - p2.x;
        double dy2 = p3.y - p2.y;

        if (dy1 != 0 || dy2 != 0 || dx1 != dx2)
        {
            throw std::invalid_argument("Invalid parallelogram definition");
        }
    }

    void Parallelogram::move(point_t p)
    {
        double center_x = (p1_.x + p3_.x) / 2;
        double center_y = (p1_.y + p3_.y) / 2;

        double dx = p.x - center_x;
        double dy = p.y - center_y;

        p1_.x += dx;
        p1_.y += dy;
        p2_.x += dx;
        p2_.y += dy;
        p3_.x += dx;
        p3_.y += dy;
    }

    void Parallelogram::move(double shift_x, double shift_y)
    {

        p1_.x += shift_x;
        p1_.y += shift_y;
        p2_.x += shift_x;
        p2_.y += shift_y;
        p3_.x += shift_x;
        p3_.y += shift_y;
    }

    void Parallelogram::scale(double scale)
    {

        double center_x = (p1_.x + p3_.x) / 2;
        double center_y = (p1_.y + p3_.y) / 2;

        p1_.x = center_x + scale *(p1_.x - center_x);
        p1_.y = center_y + scale * (p1_.y - center_y);
        p3_.x = center_x + scale * (p3_.x - center_x);
        p3_.y = center_y + scale * (p3_.y - center_y);
    }

    double Parallelogram::getArea() const
    {
        return std::abs(p2_.x - p1_.x) * std::abs(p3_.y - p1_.y);
    }

    rectangle_t Parallelogram::getFrameRect() const
    {
        double min_x = std::min({p1_.x, p2_.x, p3_.x});
        double max_x = std::max({p1_.x, p2_.x, p3_.x});
        double min_y = std::min({p1_.y, p2_.y, p3_.y});
        double max_y = std::max({p1_.y, p2_.y, p3_.y});

        point_t center = {(min_x + max_x) / 2, (min_y + max_y) / 2};
        double width = max_x - min_x;
        double height = max_y - min_y;

        return rectangle_t{center, width, height};
    }

    Shape* Parallelogram::clone() const
    {
        return new Parallelogram(p1_, p2_, p3_);
    }
}
