#include <iostream>
#include <cstring>
#include <stdexcept>
#include <string_reader.hpp>
#include "shape.hpp"
#include "input.hpp"
#include "output.hpp"
#include "rectangle.hpp"
#include "parallelogram.hpp"
#include "square.hpp"
#include "ellipse.hpp"
#include "scale.hpp"

int main()
{
  using namespace sakovskaia;
  Shape * shapes[1000]{};
  size_t cnt = 0;
  char * string = nullptr;
  bool scaleFlag = false;
  bool errorFlag = false;
  while (!scaleFlag)
  {
    if (!std::cin.good())
    {
      std::cerr << "Input error\n";
      freeShapes(shapes, cnt);
      return 1;
    }
    try
    {
      string = readString(std::cin);
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      delete [] string;
      freeShapes(shapes, cnt);
      return 2;
    }
    constexpr size_t shapes_cnt = 5;
    const char * shapes_my[shapes_cnt] = {"RECTANGLE", "PARALLELOGRAM", "SQUARE", "ELLIPSE", "SCALE"};
    try
    {
      for (size_t i = 0; i < shapes_cnt; i++)
      {
        size_t shape_name = std::strlen(shapes_my[i]);
        if (std::strncmp(shapes_my[i], string, shape_name) == 0)
        {
          if (i == 0)
          {
            Shape * shape = inputRectangle(string);
            if (shape != nullptr)
            {
              shapes[cnt++] = shape;
            }
          }
          if (i == 1)
          {
            Shape * shape = inputParallelogram(string);
            if (shape != nullptr)
            {
              shapes[cnt++] = shape;
            }
          }
          if (i == 2)
          {
            Shape * shape = inputSquare(string);
            if (shape != nullptr)
            {
              shapes[cnt++] = shape;
            }
          }
          if (i == 3)
          {
            Shape * shape = inputEllipse(string);
            if (shape != nullptr)
            {
              shapes[cnt++] = shape;
            }
          }
          if (i == 4)
          {
            scaleFlag = true;
            for (size_t i = 0; i < cnt; ++i)
            {
              scaleOp(string, shapes, cnt, std::cout);
            }
          }
        }
      }
    }
    catch (const std::invalid_argument & e)
    {
      errorFlag = true;
    }
    catch (const std::logic_error & e)
    {
      std::cerr << e.what() << "\n";
      delete [] string;
      freeShapes(shapes, cnt);
      return 1;
    }
    delete [] string;
  }
  if (errorFlag)
  {
    std::cerr << "Error\n";
  }
  freeShapes(shapes, cnt);
}
