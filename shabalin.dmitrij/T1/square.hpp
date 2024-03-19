#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "shape.hpp"

namespace shabalin
{
    class Square : public Shape
    {
    public:
        Square(double left_bottom_x, double left_bottom_y, double side_length);
        Square(point_t center, double side_length);
        void move(point_t p) override;
        void move(double shift_x, double shift_y) override;
        void scale(double scale) override;
        double getArea() const override;
        rectangle_t getFrameRect() const override;
        Shape* clone() const override;
    private:
        point_t left_bottom_;
        double side_length_;
    };
}

#endif
