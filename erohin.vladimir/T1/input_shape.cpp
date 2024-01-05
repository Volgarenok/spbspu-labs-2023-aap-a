#include "input_shape.hpp"
#include <stdexcept>
#include <iostream>
#include "triangle.hpp"
#include "shape.hpp"
#include "input_string.hpp"
#include "parse.hpp"

erohin::Shape** erohin::inputShape(std::istream& input, erohin::Shape** shape, size_t& size, point_t& pos, double& ratio)
{
    const size_t iter_size = 1;
    size = iter_size;
    Shape** result = nullptr;
    Shape** temp = nullptr;
    char* str = nullptr;
    size_t i = 0;
    try
    {
        result = new Shape* [iter_size];
        str = new char[20 + 1]{'0'};
        while (!input.eof())
        {
            if (size == i)
            {
                temp = resize(result, size, iter_size);
                size += iter_size;
                delete[] result;
                result = temp;
            }
            str = inputString(input, str);
            Shape* shape_ptr = parseShape(str, pos, ratio);
            result[i] = shape_ptr;
            ++i;
        }
    }
    catch (const std::bad_alloc& e)
    {
        delete[] result;
        delete[] str;
        throw e;
    }
    delete[] str;
    return result;
}

erohin::Shape** erohin::resize(erohin::Shape** shape, size_t size, size_t shift)
{
    erohin::Shape** resized = new Shape*[size + shift];
    for (size_t i = 0; i < size; ++i)
    {
        resized[i] = shape[i];
    }
    return resized;
}

bool erohin::isNullFrameRect(erohin::rectangle_t frameRect)
{
    bool isNullPoint = (frameRect.pos.x == 0.0) && (frameRect.pos.y == 0.0);
    return isNullPoint && (frameRect.height == 0.0) && (frameRect.width == 0.0);
}
