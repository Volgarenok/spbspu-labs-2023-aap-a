#ifndef PARALLELOGRAM_HPP
#define PARALLELOGRAM_HPP

#include "shape.hpp"

namespace shabalin
{
    class Parallelogram : public Shape
    {
    public:
        Parallelogram(point_t p1, point_t p2, point_t p3);
        void move(point_t p) override;
        void move(double shift_x, double shift_y) override;
        void scale(double scale) override;
        double getArea() const override;
        rectange_t getFrameRect() const override;
        Shape* clone() const override;

    private:
        point_t p1_;
        point_t p2_;
        point_t p3_;
    };
}

#endif
