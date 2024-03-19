#ifndef BASE_TYPES_HPP
#define BASE_TYPES_HPP

namespace shabalin
{
struct point_t
{
    double x, y;
};
struct rectangle_t
{
    point_t pos;
    double width, height;
    point_t bl() const
    {
        return {pos.x - width / 2.0, pos.y - height / 2.0};
    }
    point_t ur() const
    {
        return {pos.x + width / 2.0, pos.y + height / 2.0};
    }
};
}
#endif
