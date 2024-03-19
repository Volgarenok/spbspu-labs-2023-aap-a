#include "triangle.hpp"
#include <algorithm>
#include <cmath>
#include <stdexcept>

namespace shabalin
{
Triangle::Triangle(point_t p1, point_t p2, point_t p3) :
p1_(p1),
p2_(p2),
p3_(p3)
{
  bool isErrorShown = false;
  if ((!isTriangle(p1, p2, p3)) && !isErrorShown)
  {
    throw std::invalid_argument("Can't create Triangle with given parameters");
    isErrorShown = true;
  }
}

bool Triangle::isTriangle(point_t p1, point_t p2, point_t p3)
{
    const double d1 = distance(p1, p2);
    const double d2 = distance(p1, p3);
    const double d3 = distance(p2, p3);
    return (d1 + d2 > d3) && (d1 + d3 > d2) && (d2 + d3 > d1);
}

double Triangle::distance(point_t p1, point_t p2)
{
    return std::sqrt(std::pow(p2.x - p1.x, 2.0) + std::pow(p2.y - p1.y, 2.0));
}

void Triangle::move(point_t p)
{
    double dx = p.x - (p1_.x + p2_.x + p3_.x) / 3.0;
    double dy = p.y - (p1_.y + p2_.y + p3_.y) / 3.0;

    p1_.x += dx;
    p1_.y += dy;
    p2_.x += dx;
    p2_.y += dy;
    p3_.x += dx;
    p3_.y += dy;
}

void Triangle::move(double shift_x, double shift_y)
{
    p1_.x += shift_x;
    p1_.y += shift_y;
    p2_.x += shift_x;
    p2_.y += shift_y;
    p3_.x += shift_x;
    p3_.y += shift_y;
}

void Triangle::scale(double scale)
{
    double dx = p1_.x;
    double dy = p1_.y;

    p1_.x = dx + (p1_.x - dx) * scale;
    p1_.y = dy + (p1_.y - dy) * scale;
    p2_.x = dx + (p2_.x - dx) * scale;
    p2_.y = dy + (p2_.y - dy) * scale;
    p3_.x = dx + (p3_.x - dx) * scale;
    p3_.y = dy + (p3_.y - dy) * scale;
}

double Triangle::getArea() const
{
    double a = std::sqrt(std::pow(p2_.x - p1_.x, 2) + std::pow(p2_.y - p1_.y, 2));
    double b = std::sqrt(std::pow(p3_.x - p2_.x, 2) + std::pow(p3_.y - p2_.y, 2));
    double c = std::sqrt(std::pow(p1_.x - p3_.x, 2) + std::pow(p1_.y - p3_.y, 2));
    double p = (a + b + c) / 2;
    return std::sqrt(p * (p - a) * (p - b) * (p - c));
}

rectangle_t Triangle::getFrameRect() const
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

Shape* Triangle::clone() const
{
    return new Triangle(p1_, p2_, p3_);
}
}
